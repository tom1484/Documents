class Cube {
  int dim;
  NVector[] points;
  NVector[] rotated_points;
  NVector[] projected_points;
  
  NVector cam, scene;
  
  boolean unRotated;
  
  Cube(int dim, float length) {
    this.dim = dim;
    points = new NVector[(1 << dim)];
    
    // initialize all 2^D points
    float[] v = new float[dim];
    for (int s = 0; s < (1 << dim); s ++) {
      for (int i = 0; i < dim; i ++) {
        if ((s & (1 << i)) == 0) {
          v[i] = 0.5 * length;
        } else {
          v[i] = -0.5 * length;
        }
      }
      points[s] = new NVector(dim, v);
    }
    
    // initialize all other points
    this.rotated_points = Arrays.copyOf(points, (1 << this.dim));
    this.projected_points = Arrays.copyOf(points, (1 << this.dim));
    
    // initialize camera and scene
    for (int i = 0; i < dim; i ++) {
      v[i] = 0;
    }
    cam = scene = new NVector(dim, v);
    
    unRotated = true;
  }
  
  void rotate(int d1, int d2, float angle) {
    // create rotation matrix
    float[][] rotation = UnitMatrix(this.dim);
    rotation[d1][d1] = rotation[d2][d2] = cos(angle);
    rotation[d1][d2] = rotation[d2][d1] = sin(angle);
    if ((d1 + d2) % 2 == 1) {
      rotation[d1][d2] *= -1;
    } else {
      rotation[d2][d1] *= -1;
    }
    
    // update rotated_points
    for (int i = 0; i < (1 << this.dim); i ++) {
      if (unRotated) {
        this.rotated_points[i] = 
          toNVector(MatrixMult(rotation, this.points[i].toMatrix()));
      } else {
        this.rotated_points[i] = 
          toNVector(MatrixMult(rotation, this.rotated_points[i].toMatrix()));
      }
    }
    unRotated = false;
  }
  
  void project(int target) {
    // make copies of variable
    NVector[] p = Arrays.copyOf(this.rotated_points, (1 << this.dim));
    float r = (height / 2) * (1 / tan(PI / 6) - 1) * 1.5;
    
    // project all points to target dimension with the formula:
    //   d = cam - P1
    //   mu = (Pp - P1) * n / d * n
    //   Pt = P1 + mu * d
    for (int i = this.dim; i > target; i --) {
      for (int j = 0; j < p.length; j ++) {       
        float w = p[j].get(i - 1);
        float d = r - w;
        float mu = -w / d;
        NVector dv = p[j].mult(-1);
        dv.set(i - 1, r + dv.get(i - 1));
        p[j] = p[j].add(dv.mult(mu)).project(i - 1);
      }
    }
    //for (int i = this.dim; i > target; i --) {
    //  c.set(i - 1, r);
    //  NVector n = s.sub(c);
    //  for (int j = 0; j < p.length; j ++) {
    //    NVector d = c.sub(p[j]);
    //    float mu = s.sub(p[j]).dot(n) / d.dot(n);
    //    p[j] = p[j].add(d.mult(mu)).project(i - 1);
    //  }
    //  c = c.project(i - 1);
    //  s = s.project(i - 1);
    //}
    this.projected_points = p;
  }
  
  void draw(float pointWeight, float lineWeight) {
    project(3);
    
    stroke(255, 0, 0);
    strokeWeight(pointWeight);
    for (int i = 0; i < (1 << this.dim); i ++) {
      this.point3D(this.projected_points[i]);
      //this.point2D(this.projected_points[i]);
    }
    
    stroke(255);
    strokeWeight(lineWeight);
    this.connect(this.dim, 0, (1 << this.dim));
    
    unRotated = true;
  }
  
  void connect(int d, int l, int r) {
    if (d == 1) {
      // connect lower-dimensional cubes separately 
      this.line3D(this.projected_points[l], 
                  this.projected_points[l + 1]);
      //this.line2D(this.projected_points[l], 
                  //this.projected_points[l + 1]);
    } else {
      // combine all lower-dimensional cubes
      this.connect(d - 1, l, r - (1 << (d - 1)));
      this.connect(d - 1, l + (1 << (d - 1)), r);
      for (int i = l; i < l + (1 << (d - 1)); i ++) {
        this.line3D(this.projected_points[i], 
                    this.projected_points[i + (1 << (d - 1))]);
        //this.line2D(this.projected_points[i], 
                    //this.projected_points[i + (1 << (d - 1))]);
      }
    }
    return ;
  }
  
  void line3D(NVector a, NVector b) {
    line(a.get(0), a.get(1), a.get(2), 
         b.get(0), b.get(1), b.get(2));
  }
  
  void point3D(NVector a) {
    point(a.get(0), a.get(1), a.get(2));
  }
  
  void line2D(NVector a, NVector b) {
    line(a.get(0), a.get(1), 
         b.get(0), b.get(1));
  }
  
  void point2D(NVector a) {
    point(a.get(0), a.get(1));
  }
  
  NVector get(int i) {
    return this.points[i];
  }
}
