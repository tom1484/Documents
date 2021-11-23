class Plane {

  float x, y, z, d;
  
  Plane(float x, float y, float z, float d) {
    this.x = x;
    this.y = y;
    this.z = z;
    this.d = d;
  }
  
  ArrayList<Point> get_intersection(Box B) {
    
    //Point res[] = new Point[12];
    ArrayList<Point> res = new ArrayList();
    
    for (int i = 0; i < 12; i ++) {
      Edge E = B.edges[i];
      
      float t = (this.d - E.s.x * this.x - E.s.y * this.y - E.s.z * this.z) / 
                (E.vec.x * this.x + E.vec.y * this.y + E.vec.z * this.z);
      //print(t);
      //print(' ');
      
      if (t < 0 || t > 1)
        continue;
      
      res.add(
        new Point(
          E.s.x + E.vec.x * t, 
          E.s.y + E.vec.y * t, 
          E.s.z + E.vec.z * t
        )
      );
    }
    
    //print('\n');
    
    return res;
  }

}
