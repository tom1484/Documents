class NVector {
  int dim;
  float[] v;
  
  NVector(int dim, float[] v) {
    this.dim = dim;
    this.v = Arrays.copyOf(v, v.length);
  }
  
  float get(int d) {
    return this.v[d];
  }
  
  void set(int d, float val) {
    this.v[d] = val;
  }
  
  NVector add(NVector other) {
    float[] t = new float[this.dim];
    for (int i = 0; i < this.dim; i ++) {
      t[i] = this.get(i) + other.get(i);
    }
    return new NVector(this.dim, t);
  }
  
  NVector sub(NVector other) {
    float[] t = new float[this.dim];
    for (int i = 0; i < this.dim; i ++) {
      t[i] = this.get(i) - other.get(i);
    }
    return new NVector(this.dim, t);
  }
  
  NVector mult(float scale) {
    float[] t = new float[this.dim];
    for (int i = 0; i < this.dim; i ++) {
      t[i] = this.get(i) * scale;
    }
    return new NVector(this.dim, t);
  }
  
  NVector div(float scale) {
    float[] t = new float[this.dim];
    for (int i = 0; i < this.dim; i ++) {
      t[i] = this.get(i) / scale;
    }
    return new NVector(this.dim, t);
  }
  
  float dot(NVector other) {
    float res = 0;
    for (int i = 0; i < this.dim; i ++) {
      res += this.get(i) * other.get(i);
    }
    return res;
  }
  
  NVector normalize() {
    float r = sqrt(this.abs());
    this.div(r);
    return this;
  }
  
  NVector project(int d) {
    return new NVector(d, Arrays.copyOf(this.v, d));
  }
  
  float abs() {
    float res = 0;
    for (int i = 0; i < this.dim; i ++) {
      res += pow(this.get(i), 2);
    }
    return res;
  }
  
  float[][] toMatrix() {
    float[][] mat = new float[this.dim][1];
    for (int i = 0; i < this.dim; i ++) {
      mat[i][0] = this.get(i);
    }
    return mat;
  }
  
  NVector copy() {
    return new NVector(this.dim, Arrays.copyOf(this.v, this.dim));
  }
}
