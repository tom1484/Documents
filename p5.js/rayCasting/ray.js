class ray {
    constructor(x, y, angle) {
        this.x = x, this.y = y;
        this.dir = p5.Vector.fromAngle(radians(angle));
        this.dir.y *= -1;
        this.length = 10;
    }

    show() {
        stroke(255);
        strokeWeight(1);
        line(this.x,
             this.y,
             this.x + this.dir.x * this.length,
             this.y + this.dir.y * this.length);
    }

    showByLength(length, maxX, maxY) {
        stroke(255);
        strokeWeight(0.5);
        line(this.x,
             this.y,
             this.x + this.dir.x * length,
             this.y + this.dir.y * length);
    }

    setDir(x, y) {
        const len = sqrt((x - this.x) * (x - this.x) + (y - this.y) * (y - this.y));
        this.dir = createVector((x - this.x) / len, (y - this.y) /len);
    }

    setPos(x, y) {
        this.x = x, this.y = y;
    }

    cast(boundary) {
        const x1 = this.x, x2 = this.x + this.dir.x;
        const y1 = this.y, y2 = this.y + this.dir.y;
        const x3 = boundary.x1, x4 = boundary.x2;
        const y3 = boundary.y1, y4 = boundary.y2;

        const den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
        if (den == 0) return 1e9;

        const t = ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
        const u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;

        const px = x1 + t * (x2 - x1);
        const py = y1 + t * (y2 - y1);

        if (u >= 0.0 && u <= 1.0 && t >= 0) {
            return dist(this.x, this.y, px, py);
        }
        else {
            return 1e9;
        }
    }
}
