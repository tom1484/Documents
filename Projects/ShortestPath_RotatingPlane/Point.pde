class Point {
  
  float x, y, z;
  
  Point(float x, float y, float z) {
    this.x = x;
    this.y = y;
    this.z = z;
  }
    
  Point add(Point A) {
    Point res = new Point(
      this.x + A.x, 
      this.y + A.y, 
      this.z + A.z
    );
    
    return res;
  }

  Point sub(Point A) {
    Point res = new Point(
      this.x - A.x, 
      this.y - A.y, 
      this.z - A.z
    );
    
    return res;
  }

};
