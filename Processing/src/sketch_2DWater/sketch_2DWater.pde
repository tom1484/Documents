int width = 600, height = 600;
int cols;
int rows;
float[][] current;
float[][] previous;

float dampening = 0.999;

void setup() {
  surface.setSize(width, height);
  cols = width;
  rows = height;
  current = new float[cols][rows];
  previous = new float[cols][rows];
}

void mouseDragged() {
  if (mouseX < width && mouseX >= 0 && mouseY < height && mouseY >= 0)
    previous[mouseX][mouseY] = 500;
}

void draw() {
  background(0);
  
  loadPixels();
  
  int r = 1;
  for (int i = r; i < cols-r; i++) {
    for (int j = r; j < rows-r; j++) {
      current[i][j] = (
        previous[i-r][j] + 
        previous[i+r][j] +
        previous[i][j-r] + 
        previous[i][j+r]) / 2 -
        current[i][j];
      current[i][j] = current[i][j] * dampening;
      int index = i + j * cols;
      pixels[index] = color(current[i][j]);
    }
  }
  updatePixels();

  float[][] temp = previous;
  previous = current;
  current = temp;
}
