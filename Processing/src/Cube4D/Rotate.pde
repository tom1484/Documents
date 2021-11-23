void rotateXY(P4Vector[] p, P4Vector[] pr, float angle) {
  float[][] rotation = {
    {cos(angle), -sin(angle), 0, 0}, 
    {sin(angle), cos(angle), 0, 0}, 
    {0, 0, 1, 0}, 
    {0, 0, 0, 1}
  };
  
  for (int i = 0; i < p.length; i ++) {
    pr[i] = toP4Vector(MatrixMult(rotation, p[i].toMatrix()));
  }
}

void rotateXZ(P4Vector[] p, P4Vector[] pr, float angle) {
  float[][] rotation = {
    {cos(angle), 0, sin(angle), 0},
    {0, 1, 0, 0}, 
    {-sin(angle), 0, cos(angle), 0}, 
    {0, 0, 0, 1}
  };
  
  for (int i = 0; i < p.length; i ++) {
    pr[i] = toP4Vector(MatrixMult(rotation, p[i].toMatrix()));
  }
}

void rotateXW(P4Vector[] p, P4Vector[] pr, float angle) {
  float[][] rotation = {
    {cos(angle), 0, 0, -sin(angle)}, 
    {0, 1, 0, 0}, 
    {0, 0, 1, 0}, 
    {sin(angle), 0, 0, cos(angle)}
  };
  
  for (int i = 0; i < p.length; i ++) {
    pr[i] = toP4Vector(MatrixMult(rotation, p[i].toMatrix()));
  }
}

void rotateYZ(P4Vector[] p, P4Vector[] pr, float angle) {
  float[][] rotation = {
    {1, 0, 0, 0}, 
    {0, cos(angle), -sin(angle), 0},
    {0, sin(angle), cos(angle), 0}, 
    {0, 0, 0, 1}
  };
  
  for (int i = 0; i < p.length; i ++) {
    pr[i] = toP4Vector(MatrixMult(rotation, p[i].toMatrix()));
  }
}

void rotateYW(P4Vector[] p, P4Vector[] pr, float angle) {
  float[][] rotation = {
    {1, 0, 0, 0}, 
    {0, cos(angle), 0, sin(angle)},
    {0, 0, 1, 0}, 
    {0, -sin(angle), 0, cos(angle)}
  };
  
  for (int i = 0; i < p.length; i ++) {
    pr[i] = toP4Vector(MatrixMult(rotation, p[i].toMatrix()));
  }
}

void rotateZW(P4Vector[] p, P4Vector[] pr, float angle) {
  float[][] rotation = {
    {1, 0, 0, 0}, 
    {0, 1, 0, 0}, 
    {0, 0, cos(angle), -sin(angle)},
    {0, 0, sin(angle), cos(angle)}
  };
  
  for (int i = 0; i < p.length; i ++) {
    pr[i] = toP4Vector(MatrixMult(rotation, p[i].toMatrix()));
  }
}
