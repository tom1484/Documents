class Camera {
  PVector eye;
  PVector up;
  
  float scale;
  
  Camera(PVector eye, PVector up) {
    this.eye = eye.copy();
    this.up = up.copy();
    this.up.div(up.mag());
    
    scale = 1;
  }
  
  void zoom(float scale) {
    eye.mult(scale);
    this.scale *= scale;
  }
  
  void rotateBySide(float deg) {
    PVector x_vec = this.eye.copy();
    PVector y_vec = this.up.copy();
    x_vec.normalize();
    
    float x = eye.mag();
    float y = 1;
    
    this.eye = x_vec.copy().mult(x * cos(deg)).add(
               y_vec.copy().mult(x * sin(deg)));
    this.up = x_vec.copy().mult(-y * sin(deg)).add(
              y_vec.copy().mult(y * cos(deg)));
  }
  
  void rotateByUp(float deg) {
    PVector x_vec = this.eye.copy();
    PVector y_vec = this.up.copy().cross(x_vec);
    x_vec.normalize();
    y_vec.normalize();
    
    float x = eye.mag();
    
    this.eye = x_vec.copy().mult(x * cos(deg)).add(
               y_vec.copy().mult(x * sin(deg)));
  }
}
