void setup() {
  size(900, 900, P3D);
  camera(70.0, 35.0, 120.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  hint(DISABLE_DEPTH_TEST);
}

void draw() {
  background(0);

  stroke(255);
  strokeWeight(4);

  Box b = new Box(new Point(0, 0, 0), new Point(10, 10, 10));
  b.draw();

  Plane p = new Plane(-1, -1, 1, -5);
  ArrayList<Point> inters = p.get_intersection(b);

  stroke(255, 0, 0);
  strokeWeight(10);
  for (int i = 0; i < inters.size(); i ++) {
    point(inters.get(i).x, inters.get(i).y, inters.get(i).z);
  }
}
