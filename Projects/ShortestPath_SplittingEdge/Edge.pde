class Edge {
  
  Point s, e;
  Point vec;
  
  Edge(Point s, Point e) {
    this.s = s;
    this.e = e;
    
    this.vec = this.e.sub(this.s);
  }
  
  void draw() {
    line(s.x, s.y, s.z, 
         e.x, e.y, e.z);
  }
  
}
