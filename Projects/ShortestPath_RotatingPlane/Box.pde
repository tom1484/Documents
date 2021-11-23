class Box {
  
  Edge edges[] = new Edge[12];
  
  Box(Point min, Point max) {
    
    Point vec = max.sub(min);
    Point vec_x = new Point(vec.x, 0, 0);
    Point vec_y = new Point(0, vec.y, 0);
    Point vec_z = new Point(0, 0, vec.z);
    
    edges[0] = new Edge(min, min.add(vec_x));
    edges[1] = new Edge(min, min.add(vec_y));
    edges[2] = new Edge(min, min.add(vec_z));
    
    edges[3] = new Edge(max.sub(vec_x), max);
    edges[4] = new Edge(max.sub(vec_y), max);
    edges[5] = new Edge(max.sub(vec_z), max);
    
    edges[6] = new Edge(min.add(vec_x), min.add(vec_x).add(vec_y));
    edges[7] = new Edge(min.add(vec_y), min.add(vec_x).add(vec_y));
    
    edges[8] = new Edge(min.add(vec_x), min.add(vec_x).add(vec_z));
    edges[9] = new Edge(min.add(vec_z), min.add(vec_x).add(vec_z));

    edges[10] = new Edge(min.add(vec_y), min.add(vec_y).add(vec_z));
    edges[11] = new Edge(min.add(vec_z), min.add(vec_y).add(vec_z));

  }
  
  void draw() {
    for (int i = 0; i < 12; i ++) {
      edges[i].draw();
    }
  }
  
}
