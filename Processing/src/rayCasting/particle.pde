class particle {
    float x, y, angleRan, angleOff, dir;
    ArrayList <ray> rays;
    float sceneW, sceneH;
    ArrayList <Float> castRes;
  
    particle(float x, float y, float angleRan, float angleOff, float dir) {
        this.x = x;
        this.y = y;
        this.angleRan = angleRan;
        this.angleOff = angleOff;
        this.dir = dir;
        this.rays = new ArrayList <ray>();
        this.castRes = new ArrayList <Float>();

        for (float a = 0; a < this.angleRan; a += angleOff) {
            this.rays.add(new ray(x, y, a + dir));
        }
    }

    void setScene(float w, float h) {
        this.sceneW = w;
        this.sceneH = h;
    }

    void updatePos(float x, float y) {
        if (this.x + x < 0 || this.x + x > this.sceneW ||
            this.y + y < 0 || this.y + y > this.sceneH) {
            return ;
        }

        this.x += x;
        this.y += y;
        this.rays = new ArrayList <ray>();
        for (float a = 0; a < this.angleRan; a += this.angleOff) {
            this.rays.add(new ray(this.x, this.y, a + this.dir));
        }
    }

    void updateDir(float angle) {
        this.dir += angle;
        this.rays = new ArrayList <ray>();
        for (float a = 0; a < this.angleRan; a += this.angleOff) {
            this.rays.add(new ray(this.x, this.y, a + this.dir));
        }
    }

    void cast(ArrayList <boundary> walls) {
        this.castRes = new ArrayList <Float>();
      
        for (int r = 0; r < this.rays.size(); r ++) {
            float record = dist(0, 0, sceneW, sceneH);

            for (int w = 0; w < walls.size(); w ++) {
              float dis = this.rays.get(r).cast(walls.get(w));
              if (dis != 1e9) {
                record = min(record, dis);
              }
            }

            this.castRes.add(record);
            this.rays.get(r).showByLength(record);
        }
        Collections.reverse(castRes);
    }

    void visualize() {
        for (int i = 0; i < this.castRes.size(); i ++) {
            float res = this.castRes.get(i);
            float maxLength = dist(0, 0, this.sceneW, this.sceneH);

            float brightness = map(pow((maxLength - res) / maxLength, 2) * maxLength, 0, maxLength, 0, 255);
            float h = map(res, 0, maxLength, 0, this.sceneH * 0.45);

            fill(brightness);
            noStroke();
            rect(this.sceneW / this.castRes.size() * i, h,
                 this.sceneW / this.castRes.size() + 1, this.sceneH - h * 2);
        }
    }
}
