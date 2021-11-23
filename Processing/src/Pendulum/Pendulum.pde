final int N = 30;
final float g = 9.8;
final float w = 150;

SimplePendulum[] pendulums = new SimplePendulum[N];

void setup() {
  size(900, 900);
  
  for (int i = 0; i < N; i ++) {
    float L = 300 + 400.0 * i / (N - 1);
    float phi = asin(w / L);
    
    float x = width / 2.0;
    float y = 50 + L * (1 - cos(phi));
    
    pendulums[i] = new SimplePendulum(
      new PVector(x, y), L, g
    );
    
    float c_r = sin(0 + 2 * PI * i / N) * 180 + 75;
    float c_g = sin(2 + 2 * PI * i / N) * 180 + 75;
    float c_b = sin(4 + 2 * PI * i / N) * 180 + 75;
    
    pendulums[i].initialize(
      phi, 0, 0.5, color(c_r, c_g, c_b)
    );
  }
}

void draw() {
  background(255);
  
  for (int i = 0; i < N; i ++) {
    SimplePendulum P = pendulums[i];
    PVector end = new PVector(
      P.pivot.x + P.L * sin(P.phi), 
      P.pivot.y + P.L * cos(P.phi)
    );
    
    stroke(120);
    strokeWeight(1);
    line(P.pivot.x, P.pivot.y, end.x, end.y);
    
    stroke(P.c);
    strokeWeight(20);
    point(end.x, end.y);
  }
  
  for (int i = 0; i < N; i ++) {
    pendulums[i].update();
  }
}
