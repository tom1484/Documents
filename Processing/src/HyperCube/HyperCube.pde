import java.util.Arrays;

Cube cube = new Cube(7, 190);

float angle = 0;

void setup() {
  //size(800, 800, P3D);
  fullScreen(P3D);
}

void draw() {
  background(0);
  translate(width / 2, height / 2);
  //rotateX(-PI / 2);
  
  // an simple rotation requires two axises 
  //cube.rotate(0, 1, angle);
  //cube.rotate(1, 2, angle);
  //cube.rotate(2, 3, angle);
  //cube.rotate(3, 4, angle);
  //cube.rotate(4, 5, angle);
  int d = 1;
  for (int i = 0; i < cube.dim - d; i ++) {
    cube.rotate(i, i + d, angle);
  }
  d = 2;
  for (int i = 0; i < cube.dim - d; i ++) {
    cube.rotate(i, i + d, angle);
  }
  
  cube.draw(6, 1);
  
  angle += 0.01;
}
