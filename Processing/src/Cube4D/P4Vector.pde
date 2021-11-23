class P4Vector {
  float x, y, z, w;
  
  P4Vector(float x, float y, float z, float w) {
    this.x = x;
    this.y = y;
    this.z = z;
    this.w = w;
  }

  P4Vector add(P4Vector other) {
    P4Vector res = new P4Vector(
      this.x + other.x, 
      this.y + other.y, 
      this.z + other.z, 
      this.w + other.w
    );
    return res;
  }

  P4Vector sub(P4Vector other) {
    P4Vector res = new P4Vector(
      this.x - other.x, 
      this.y - other.y, 
      this.z - other.z, 
      this.w - other.w
    );
    return res;
  }

  P4Vector mult(float scale) {
    P4Vector res = new P4Vector(
      this.x * scale, 
      this.y * scale, 
      this.z * scale, 
      this.w * scale
    );
    return res;
  }

  P4Vector div(float scale) {
    P4Vector res = new P4Vector(
      this.x / scale, 
      this.y / scale, 
      this.z / scale, 
      this.w / scale
    );
    return res;
  }

  float dot(P4Vector other) {
    return this.x * other.x +
           this.y * other.y +
           this.z * other.z +
           this.w * other.w;
  }
  
  P4Vector normalize() {
    float r = sqrt(this.abs());
    this.div(r);
    return this;
  }

  float[][] toMatrix() {
    float[][] mat = {{this.x}, {this.y}, {this.z}, {this.w}};
    return mat;
  }
  
  float abs() {
    return pow(this.x, 2) + pow(this.y, 2) + pow(this.z, 2) + pow(this.w, 2);
  }
  
  P4Vector copy() {
    P4Vector vec = new P4Vector(this.x, this.y, this.z, this.w); 
    return vec;
  }
}
