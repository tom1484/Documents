class ray {
    constructor(x, y, angle) {
        this.x = x, this.y = y;
        this.angle = angle;
        this.dir = p5.Vector.fromAngle(radians(angle));
        this.dir.y *= -1;
    }

    show(len) {
        stroke(255);
        strokeWeight(2);
        line(this.x, this.y, this.x + this.dir.x * len, this.y + this.dir.y * len);
    }

    setPos(x, y) {
        this.x = x, this.y = y;
    }

    rotate(angle) {
        this.angle += angle;
        this.dir = p5.Vector.fromAngle(radians(this.angle));
    }

    march(stuff) {
        let record = [];
        let x = this.x, y = this.y;
        let len = 0;

        while (true) {
            let minD = INF;

            for (let i = 0; i < stuff.length; i ++) {
                minD = min(minD, stuff[i].signedDistance(x, y));
            }

            if (minD < 0) break;

            record.push(createVector(x, y, minD));
            len += minD;

            x += this.dir.x * minD;
            y += this.dir.y * minD;

            if (minD < 1) break;
            if (x < 0 || x > width || y < 0 || y > height)
                break;
        }

        for (let i = 0; i < record.length; i ++) {
            noFill();
            stroke(150);
            strokeWeight(2);
            ellipse(record[i].x, record[i].y, record[i].z * 2);
        }

        stroke(150, 0, 0);
        strokeWeight(3);
        line(this.x, this.y, this.x + this.dir.x * len, this.y + this.dir.y * len);

        stroke(255);
        strokeWeight(5);
        point(this.x, this.y);
    }
}
