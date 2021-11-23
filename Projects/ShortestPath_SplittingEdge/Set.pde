class Set {
  
  float min, max;
  
  Set(float min, float max) {
    this.min = min;
    this.max = max;
  }
  
  Set intersect(Set S) {
    
    Set res = new Set(
      max(this.min, S.min), 
      min(this.max, S.max)
    );
    
    if (res.min >= res.max) {
      res.min = res.max = -1;
    }
    
    return res;
  }
  
  void show() {
    print(this.min);
    print(" ");
    print(this.max);
    print("\n");
  }
  
}
