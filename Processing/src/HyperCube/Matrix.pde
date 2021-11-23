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

NVector toNVector(float[][] m) {
  float[] t = new float[m.length];
  for (int i = 0; i < m.length; i ++) {
    t[i] = m[i][0];
  }
  return new NVector(m.length, t);
}

float[][] UnitMatrix(int d) {
  float[][] m = new float[d][d];
  for (int i = 0; i < d; i ++) {
    for (int j = 0; j < d; j ++) {
      if (i == j) {
        m[i][j] = 1;
      } else {
        m[i][j] = 0;
      }
    }
  }
  return m;
}
