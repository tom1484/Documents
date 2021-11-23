class Key {
  boolean[] status = new boolean[256];
  
  Key() {
    for (int i = 0; i < 256; i ++)
      status[i] = false;
  }
  
  void press(char c1, char c2) {
    status[int(c1)] = true;
    status[int(c2)] = true;
  }
  
  void release(char c1, char c2) {
    status[int(c1)] = false;
    status[int(c2)] = false;
  }
  
  boolean pressed(char c1, char c2) {
    return status[int(c1)] || status[int(c2)];
  }
}
