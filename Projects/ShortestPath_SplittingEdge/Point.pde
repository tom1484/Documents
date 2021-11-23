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
  
  Point mult(float F) {
    Point res = new Point(
      this.x * F, 
      this.y * F, 
      this.z * F
    );
    
    return res;
  }
  
  float length() {
    return sqrt(pow(this.x, 2) + pow(this.y, 2) + pow(this.z, 2));
  }
  
  void draw() {
    point(this.x, this.y, this.z);
  }

};
