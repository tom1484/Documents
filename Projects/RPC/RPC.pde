Camera cam;
Key key_set;
KozAvoid koz;

float cor_scale = 50.0;
float rotation_rate = 2;

PVector center = new PVector(10.925, -8.8, 4.945);
PVector A_prime = new PVector(11.42, -9.8, 5.39);

void setup() {
  size(1000, 1000, P3D);
  
  cam = new Camera(new PVector(10, -10, -5), 
                   new PVector(0.222, -0.222, 0.888));
  cam.zoom(20.0);
  
  key_set = new Key();
  
  //koz = new KozAvoid(2, new PVector(), new PVector(10.23, -8.12, 5.45), new PVector(), false);
  koz = new KozAvoid(7, new PVector(), A_prime, new PVector(), false);
}

void draw() {
  background(0);
  
  camera(cam.eye.x, cam.eye.y, cam.eye.z, 0, 0, 0, cam.up.x, cam.up.y, cam.up.z);
  scale(cor_scale, cor_scale, cor_scale);
  
  // draw xyz axis
  strokeWeight(weight(3));
  stroke(255, 0, 0);
  
  line(0, 0, 0, 1000, 0, 0);
  stroke(0, 255, 0);
  line(0, 0, 0, 0, 1000, 0);
  stroke(0, 0, 255);
  line(0, 0, 0, 0, 0, 1000);
  
  translate(-center.x, -center.y, -center.z);
  
  // KIZ
  stroke(50, 200, 50);
  fill(100, 150, 100, 50);
  //noFill();
  
  draw_box(new PVector(10.3, -10.2, 4.32), new PVector(11.55, -7.4, 5.57), 
           color(50, 200, 50), color(100, 150, 100, 50));
  draw_box(new PVector(9.5, -10.5, 4.02), new PVector(10.5, -9.6, 4.8), 
           color(50, 200, 50), color(100, 150, 100, 50));
  
  // KOZ
  stroke(200, 50, 50);
  fill(150, 100, 100, 50);
  //noFill();
  
  for (int i = 0; i < koz.KOZList.size(); i ++)
    draw_box(koz.KOZList.get(i).min_point, koz.KOZList.get(i).max_point, 
             color(200, 50, 50), color(150, 100, 100, 50));
  
  // points
  strokeWeight(weight(8));
  stroke(200, 200, 0);
  
  point(A_prime.x, A_prime.y, A_prime.z);
  
  rotate();
}

void draw_plane(float x1, float y1, float z1, float x2, float y2, float z2) {
  float dx = x2 - x1;
  float dy = y2 - y1;
  float dz = z2 - z1;
  
  beginShape();
  
  if (dx == 0) {
    vertex(x1, y1, z1);
    vertex(x1, y1 + dy, z1);
    vertex(x1, y1 + dy, z1 + dz);
    vertex(x1, y1, z1 + dz);
  }
  else if (dy == 0) {
    vertex(x1, y1, z1);
    vertex(x1 + dx, y1, z1);
    vertex(x1 + dx, y1, z1 + dz);
    vertex(x1, y1, z1 + dz);
  }
  else if (dz == 0) {
    vertex(x1, y1, z1);
    vertex(x1 + dx, y1, z1);
    vertex(x1 + dx, y1 + dy, z1);
    vertex(x1, y1 + dy, z1);
  }
  
  endShape(CLOSE);
}

void draw_box(PVector box_min, PVector box_max, color stroke_c, color fill_c) {  
  float x = box_max.x - box_min.x;
  float y = box_max.y - box_min.y;
  float z = box_max.z - box_min.z;
  
  stroke(stroke_c);
  strokeWeight(weight(8));
  
  point(box_min.x, box_min.y, box_min.z);
  point(box_min.x + x, box_min.y, box_min.z);
  point(box_min.x + x, box_min.y + y, box_min.z);
  point(box_min.x, box_min.y + y, box_min.z);
  
  point(box_max.x, box_max.y, box_max.z);
  point(box_max.x - x, box_max.y, box_max.z);
  point(box_max.x - x, box_max.y - y, box_max.z);
  point(box_max.x, box_max.y - y, box_max.z);
  
  stroke(stroke_c);
  strokeWeight(weight(3));
  
  line(box_min.x, box_min.y, box_min.z, 
       box_min.x + x, box_min.y, box_min.z);
  line(box_min.x + x, box_min.y, box_min.z, 
       box_min.x + x, box_min.y + y, box_min.z);
  line(box_min.x + x, box_min.y + y, box_min.z, 
       box_min.x, box_min.y + y, box_min.z);
  line(box_min.x, box_min.y + y, box_min.z, 
       box_min.x, box_min.y, box_min.z);
  
  line(box_max.x, box_max.y, box_max.z, 
       box_max.x - x, box_max.y, box_max.z);
  line(box_max.x - x, box_max.y, box_max.z, 
       box_max.x - x, box_max.y - y, box_max.z);
  line(box_max.x - x, box_max.y - y, box_max.z, 
       box_max.x, box_max.y - y, box_max.z);
  line(box_max.x, box_max.y - y, box_max.z, 
       box_max.x, box_max.y, box_max.z);
       
  line(box_min.x + x, box_min.y, box_min.z, 
       box_min.x + x, box_min.y, box_min.z + z);
  line(box_min.x + x, box_min.y + y, box_min.z, 
       box_min.x + x, box_min.y + y, box_min.z + z);
  line(box_min.x, box_min.y + y, box_min.z, 
       box_min.x, box_min.y + y, box_min.z + z);
  line(box_min.x, box_min.y, box_min.z, 
       box_min.x, box_min.y, box_min.z + z);
  
  hint(DISABLE_DEPTH_TEST);
  noStroke();
  fill(fill_c);
       
  draw_plane(box_min.x, box_min.y, box_min.z, 
             box_min.x + x, box_min.y + y, box_min.z);
  
  draw_plane(box_min.x, box_min.y, box_min.z + z, 
             box_min.x + x, box_min.y + y, box_min.z + z);
  
  draw_plane(box_min.x, box_min.y, box_min.z, 
             box_min.x + x, box_min.y, box_min.z + z);
  
  draw_plane(box_min.x + x, box_min.y, box_min.z, 
             box_min.x + x, box_min.y + y, box_min.z + z);
  
  draw_plane(box_min.x + x, box_min.y + y, box_min.z, 
             box_min.x, box_min.y + y, box_min.z + z);
  
  draw_plane(box_min.x, box_min.y + y, box_min.z, 
             box_min.x, box_min.y, box_min.z + z);
  
  hint(ENABLE_DEPTH_TEST);
  
}

void mouseWheel(MouseEvent event) {
  float e = event.getCount();
  if (e > 0)
    cam.zoom(1.2);
  else
    cam.zoom(1 / 1.2);;
}

void keyPressed() {
  if (key == 'w' || key == 'W')
    key_set.press('w', 'W');
  if (key == 's' || key == 'S')
    key_set.press('s', 'S');
  if (key == 'a' || key == 'A')
    key_set.press('a', 'A');
  if (key == 'd' || key == 'D')
    key_set.press('d', 'D');
  
  if (key == '1')
    koz = new KozAvoid(1, new PVector(), A_prime, new PVector(), false);
  if (key == '2')
    koz = new KozAvoid(2, new PVector(), A_prime, new PVector(), false);
  if (key == '3')
    koz = new KozAvoid(3, new PVector(), A_prime, new PVector(), false);
  if (key == '4')
    koz = new KozAvoid(4, new PVector(), A_prime, new PVector(), false);
  if (key == '5')
    koz = new KozAvoid(5, new PVector(), A_prime, new PVector(), false);
  if (key == '6')
    koz = new KozAvoid(6, new PVector(), A_prime, new PVector(), false);
  if (key == '7')
    koz = new KozAvoid(7, new PVector(), A_prime, new PVector(), false);
  if (key == '8')
    koz = new KozAvoid(8, new PVector(), A_prime, new PVector(), false);
  print(key);
}

void keyReleased() {
  if (key == 'w' || key == 'W')
    key_set.release('w', 'W');
  if (key == 's' || key == 'S')
    key_set.release('s', 'S');
  if (key == 'a' || key == 'A')
    key_set.release('a', 'A');
  if (key == 'd' || key == 'D')
    key_set.release('d', 'D');
}

void rotate() {
  if (key_set.pressed('w', 'W'))
    cam.rotateBySide(-PI * rotation_rate / 180.0);
  if (key_set.pressed('s', 'S'))
    cam.rotateBySide(PI * rotation_rate / 180.0);
  if (key_set.pressed('a', 'A'))
    cam.rotateByUp(-PI * rotation_rate / 180.0);
  if (key_set.pressed('d', 'D'))
    cam.rotateByUp(PI * rotation_rate / 180.0);
}

float weight(float w) {
  return w / cor_scale;
}
