float[][] MatrixAdd(float[][] a, float[][] b) {
  float[][] c = new float[a.length][a[0].length];
  for (int i = 0; i < a.length; i ++) {
    for (int j = 0; j < a[i].length; j ++) {
      c[i][j] = a[i][j] + b[i][j];
    }
  }
  return c;
}

float[][] MatrixMult(float[][] a, float[][] b) {
  float[][] c = new float[a.length][b[0].length];
  for (int i = 0; i < a.length; i ++) {
    for (int j = 0; j < b[0].length; j ++) {
      c[i][j] = 0;
      for (int k = 0; k < a[0].length; k ++) {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

void printMatrix(float[][] m) {
  for (int i = 0; i < m.length; i ++) {
    for (int j = 0; j < m[i].length; j ++) {
      print(m[i][j]);
      print(' ');
    }
    print('\n');
  }
}

P4Vector toP4Vector(float[][] m) {
  P4Vector v = new P4Vector(
    m[0][0], m[1][0], m[2][0], m[3][0]
  );
  return v;
}
