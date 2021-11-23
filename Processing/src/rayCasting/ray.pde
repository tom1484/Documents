class ray {
    float x, y, length;
    PVector dir;
  
    ray(float x, float y, float angle) {
        this.x = x;
        this.y = y;
        this.dir = PVector.fromAngle(radians(angle));
        this.dir.y *= -1;
        this.length = 10;
    }

    void show() {
        stroke(255);
        strokeWeight(1);
        line(this.x,
             this.y,
             this.x + this.dir.x * this.length,
             this.y + this.dir.y * this.length);
    }

    void showByLength(float length) {
        stroke(255);
        strokeWeight(0.5);
        line(this.x,
             this.y,
             this.x + this.dir.x * length,
             this.y + this.dir.y * length);
    }

    void setDir(float x, float y) {
        float len = sqrt((x - this.x) * (x - this.x) + (y - this.y) * (y - this.y));
        this.dir = new PVector((x - this.x) / len, (y - this.y) /len);
    }

    void setPos(float x, float y) {
        this.x = x;
        this.y = y;
    }

    float cast(boundary b) {
        float x1 = this.x, x2 = this.x + this.dir.x;
        float y1 = this.y, y2 = this.y + this.dir.y;
        float x3 = b.x1, x4 = b.x2;
        float y3 = b.y1, y4 = b.y2;

        float den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (den == 0) return 1e9;

        float t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
        float u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

        float px = x1 + t * (x2 - x1);
        float py = y1 + t * (y2 - y1);

        if (u >= 0.0 && u <= 1.0 && t >= 0) {
            return dist(this.x, this.y, px, py);
        }
        else {
            return 1e9;
        }
    }
}
