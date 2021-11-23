class SimplePendulum {
  
  PVector pivot;
  float L, g;
  
  float phi, omega;
  float step;
  
  color c;
  
  SimplePendulum(PVector pivot, float L,float g) {
    this.pivot = pivot;
    this.L = L;
    this.g = g;
  }
  
  void initialize(float phi, float omega, float step, color c) {
    this.phi = phi;
    this.omega = omega;
    this.step = step;
    this.c = c;
  }
  
  void update() {
    float alpha = -g * sin(this.phi) / this.L;
    this.omega += alpha * this.step;
    this.phi += this.omega * this.step;
  }
  
};
