int N_splits = 50;

ArrayList<Box> boxes;
ArrayList<Edge> edges;
ArrayList<Point> points;

ArrayList<Integer> G[];
ArrayList<Float> weight[];
float dis[];
int prev[];
boolean vis[];

ArrayList<Point> path;

void setup() {
  size(900, 900, P3D);
  camera(70.0, 35.0, 120.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
  
  hint(DISABLE_DEPTH_TEST);
  
  // add KOZ
  boxes = new ArrayList();
  boxes.add(new Box(new Point(0, 0, 0), new Point(50, 10, 25)));
  boxes.add(new Box(new Point(0, 0, 0), new Point(50, 25, 10)));
  
  // get all edges
  edges = new ArrayList();
  for (int i = 0; i < boxes.size(); i ++) {
    edges.addAll(boxes.get(i).get_edges());
  }
  
  // add start point and target point
  points = new ArrayList();
  points.add(new Point(-10, -10, 5));
  points.add(new Point(55, 20, 5));
  
  // split one edge into N segments
  for (int i = 0; i < edges.size(); i ++) {
    Edge edge = edges.get(i);
    for (int t = 0; t <= N_splits; t ++) {
      points.add(edge.s.add(edge.vec.mult((float)t / N_splits)));
    }
  }
  
  // initialize variables for Dijkstra
  G = new ArrayList[points.size()];
  for (int i = 0; i < points.size(); i ++) {
    G[i] = new ArrayList();
  }
  
  weight = new ArrayList[points.size()];
  for (int i = 0; i < points.size(); i ++) {
    weight[i] = new ArrayList();
  }
  
  for (int i = 1; i < points.size(); i ++) {
    for (int j = 0; j < i; j ++) {
      Point A = points.get(i);
      Point B = points.get(j);
      
      if (reachable(A, B)) {
        G[i].add(j);
        G[j].add(i);
        
        float d = A.sub(B).length();
        weight[i].add(d);
        weight[j].add(d);
      }
    }
  }
  
  dis = new float[points.size()];
  for (int i = 1; i < points.size(); i ++) {
    dis[i] = 1e9;
  }
  dis[0] = 0;
  
  vis = new boolean[points.size()];
  for (int i = 1; i < points.size(); i ++) {
    vis[i] = false;
  }
  
  prev = new int[points.size()];
  for (int i = 1; i < points.size(); i ++) {
    prev[i] = i;
  }
  
  // Dijkstra
  for (int i = 0; i < points.size(); i ++) {
    int s = -1;
    float min = 1e9;
    for (int j = 0; j < points.size(); j ++) {
      if (!vis[j] && dis[j] < min) {
        s = j;
        min = dis[s];
      }
    }
    
    if (s == -1) {
      break;
    }
    vis[s] = true;
    
    for (int j = 0; j < G[s].size(); j ++) {
      int e = G[s].get(j);
      if (!vis[e] && dis[s] + weight[s].get(j) < dis[e]) {
        dis[e] = dis[s] + weight[s].get(j);
        prev[e] = s;
      }
    }
  }
  
  println("Path length: " + str(dis[1]));
  println("\nPath: ");
  
  path = new ArrayList();
  int s = 1;
  while (prev[s] != s) {
    println(str(points.get(s).x / 5) + " " + str(points.get(s).y / 5) + " " + str(points.get(s).z / 5));
    path.add(points.get(s));
    s = prev[s];
  }
  println(str(points.get(0).x / 5) + " " + str(points.get(0).y / 5) + " " + str(points.get(0).z / 5));
  path.add(points.get(0));
  
}

boolean reachable(Point s, Point e) {
  
  // determine if a box is between two points
  for (int i = 0; i < boxes.size(); i ++) {
    Box box = boxes.get(i);
    
    float dx = e.x - s.x;
    float dy = e.y - s.y;
    float dz = e.z - s.z;
    
    Set set_x, set_y, set_z;
    
    if (dx != 0) {
      if (dx > 0) {
        set_x = new Set(
          (box.min.x - s.x) / dx, 
          (box.max.x - s.x) / dx
        );
      }
      else {
        set_x = new Set(
          (box.max.x - s.x) / dx, 
          (box.min.x - s.x) / dx
        );
      }
    }
    else {
      if (e.x > box.min.x && e.x < box.max.x) {
        set_x = new Set(0, 1);
      }
      else {
        set_x = new Set(-1, -1);
      }
    }
    if (dy != 0) {
      if (dy > 0) {
        set_y = new Set(
          (box.min.y - s.y) / dy, 
          (box.max.y - s.y) / dy
        );
      }
      else {
        set_y = new Set(
          (box.max.y - s.y) / dy, 
          (box.min.y - s.y) / dy
        );
      }
    }
    else {
      if (e.y > box.min.y && e.y < box.max.y) {
        set_y = new Set(0, 1);
      }
      else {
        set_y = new Set(-1, -1);
      }
    }
    if (dz != 0) {
      if (dz > 0) {
        set_z = new Set(
          (box.min.z - s.z) / dz, 
          (box.max.z - s.z) / dz
        );
      }
      else {
        set_z = new Set(
          (box.max.z - s.z) / dz, 
          (box.min.z - s.z) / dz
        );
      }
    }
    else {
      if (e.z > box.min.z && e.z < box.max.z) {
        set_z = new Set(0, 1);
      }
      else {
        set_z = new Set(-1, -1);
      }
    }
    
    Set inter = new Set(0, 1);
    inter = inter.intersect(set_x).intersect(set_y).intersect(set_z);
    if (inter.min >= 0)
      return false;
  }
  
  return true;
}

void draw() {
  background(0);

  stroke(255);
  strokeWeight(4);

  for (int i = 0; i < edges.size(); i ++)
    edges.get(i).draw();
  
  stroke(0, 255, 0);
  strokeWeight(8);
  
  for (int i = 0; i < path.size(); i ++) {
    path.get(i).draw();
  }
  
}
