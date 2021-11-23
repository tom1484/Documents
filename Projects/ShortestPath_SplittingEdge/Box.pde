class Box {
  
  Point min, max;
  
  Box(Point min, Point max) {
    
    this.min = min;
    this.max = max;

  }
  
  ArrayList<Edge> get_edges() {
    
    ArrayList<Edge> edges = new ArrayList();
    
    Point vec = this.max.sub(this.min);
    Point vec_x = new Point(vec.x, 0, 0);
    Point vec_y = new Point(0, vec.y, 0);
    Point vec_z = new Point(0, 0, vec.z);
    
    edges.add(new Edge(min, min.add(vec_x)));
    edges.add(new Edge(min, min.add(vec_y)));
    edges.add(new Edge(min, min.add(vec_z)));
    
    edges.add(new Edge(max.sub(vec_x), max));
    edges.add(new Edge(max.sub(vec_y), max));
    edges.add(new Edge(max.sub(vec_z), max));
    
    edges.add(new Edge(min.add(vec_x), min.add(vec_x).add(vec_y)));
    edges.add(new Edge(min.add(vec_y), min.add(vec_x).add(vec_y)));
    
    edges.add(new Edge(min.add(vec_x), min.add(vec_x).add(vec_z)));
    edges.add(new Edge(min.add(vec_z), min.add(vec_x).add(vec_z)));

    edges.add(new Edge(min.add(vec_y), min.add(vec_y).add(vec_z)));
    edges.add(new Edge(min.add(vec_z), min.add(vec_y).add(vec_z)));
    
    return edges;
  }
  
}
