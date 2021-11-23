P4Vector[] points = new P4Vector[16];
P4Vector[] rotated_points = new P4Vector[16];
PVector[] projected_points = new PVector[16];

P4Vector cam, scene;

float angle = 0;

void setup() {
  size(400, 400, P3D);
  
  points[0]  = new P4Vector( 1,  1,  1,  1);
  points[1]  = new P4Vector(-1,  1,  1,  1);
  points[2]  = new P4Vector(-1, -1,  1,  1);
  points[3]  = new P4Vector( 1, -1,  1,  1);
  points[4]  = new P4Vector( 1,  1, -1,  1);
  points[5]  = new P4Vector(-1,  1, -1,  1);
  points[6]  = new P4Vector(-1, -1, -1,  1);
  points[7]  = new P4Vector( 1, -1, -1,  1);
  points[8]  = new P4Vector( 1,  1,  1, -1);
  points[9]  = new P4Vector(-1,  1,  1, -1);
  points[10] = new P4Vector(-1, -1,  1, -1);
  points[11] = new P4Vector( 1, -1,  1, -1);
  points[12] = new P4Vector( 1,  1, -1, -1);
  points[13] = new P4Vector(-1,  1, -1, -1);
  points[14] = new P4Vector(-1, -1, -1, -1);
  points[15] = new P4Vector( 1, -1, -1, -1);
  
  for (int i = 0; i < points.length; i ++) {
    points[i] = points[i].mult(50);
  }
  
  cam   = new P4Vector(0, 0, 0, (height / 2) * (1 / tan(PI / 6) - 1));
  scene = new P4Vector(0, 0, 0, 0);
}

void draw() {
  background(0);  
  translate(width / 2, height / 2);
  rotateX(-PI / 2);
  
  rotateXY(points, rotated_points, angle);
  rotateZW(rotated_points, rotated_points, angle);
  
  project(rotated_points, projected_points, cam, scene);
  
  stroke(255);
  strokeWeight(5);
  for (int i = 0; i < points.length; i ++) {
    point(projected_points[i].x, projected_points[i].y, projected_points[i].z);
  }
  strokeWeight(1);
  connect(projected_points);
  connect(projected_points);
  
  angle += 0.01;
}

void project(P4Vector[] p, PVector[] pv, P4Vector cam, P4Vector scene) {
  P4Vector n = scene.sub(cam);
  for (int i = 0; i < p.length; i ++) {
    P4Vector d = cam.sub(p[i]);
    float mu = scene.sub(p[i]).dot(n) / 
               d.dot(n);
    P4Vector projected = p[i].add(d.mult(mu));
    pv[i] = new PVector(projected.x, projected.y, projected.z);
  }
}

void connect(PVector[] p) {
  for (int i = 0; i < 4; i ++) {
    Pline(p[    i], p[    (i+1) % 4]);
    Pline(p[i + 4], p[(i+1) % 4 + 4]);
    Pline(p[    i], p[        i + 4]);
  }
  for (int i = 0; i < 4; i ++) {
    Pline(p[ i + 8], p[ (i+1) % 4 + 8]);
    Pline(p[i + 12], p[(i+1) % 4 + 12]);
    Pline(p[ i + 8], p[        i + 12]);
  }
  for (int i = 0; i < 4; i ++) {
    Pline(p[    i], p[ i + 8]);
    Pline(p[i + 4], p[i + 12]);
  }
}

void Pline(PVector p1, PVector p2) {
  line(p1.x, p1.y, p1.z, p2.x, p2.y, p2.z);
}
