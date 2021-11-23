class particle {
    constructor(x, y, angleRan, angleOff, dir) {
        this.x = x, this.y = y;
        this.angleRan = angleRan;
        this.angleOff = angleOff;
        this.dir = dir;
        this.rays = [];

        for (let a = 0, i = 0; a < this.angleRan; a += angleOff, i += 1) {
            this.rays.push(new ray(x, y, a + dir));
        }
    }

    setScene(w, h) {
        this.sceneW = w;
        this.sceneH = h;
    }

    updatePos(x, y) {
        if (this.x + x < 0 || this.x + x > this.sceneW ||
            this.y + y < 0 || this.y + y > this.sceneH) {
            return ;
        }

        this.x += x, this.y += y;
        this.rays = [];
        for (let a = 0, i = 0; a < this.angleRan; a += this.angleOff, i += 1) {
            this.rays.push(new ray(this.x, this.y, a + this.dir));
        }
    }

    setPos(x, y) {
        if (x < 0 || x > this.sceneW ||
            y < 0 || y > this.sceneH) {
            return ;
        }

        this.x = x, this.y = y;
        this.rays = [];
        for (let a = 0, i = 0; a < this.angleRan; a += this.angleOff, i += 1) {
            this.rays.push(new ray(this.x, this.y, a + this.dir));
        }
    }

    updateDir(angle) {
        this.dir += angle;
        this.rays = [];
        for (let a = 0, i = 0; a < this.angleRan; a += this.angleOff, i += 1) {
            this.rays.push(new ray(this.x, this.y, a + this.dir));
        }
    }

    cast(walls) {
        this.castRes = [];

        for (let r = 0; r < this.rays.length; r ++) {
            let record = dist(0, 0, sceneW, sceneH);

            for (let w = 0; w < walls.length; w ++) {
              let dis = this.rays[r].cast(walls[w]);
              if (dis != 1e9) {
                record = min(record, dis);
              }
            }

            this.castRes[r] = record;
        }
    }

    show() {
        for (let r = 0; r < this.rays.length; r ++) {
            this.rays[r].showByLength(this.castRes[r], canvasW, canvasH);
        }
        stroke(255, 0, 0);
        strokeWeight(5);
        point(this.x, this.y);
    }

    visualize() {
        for (let i = 0; i < this.castRes.length; i ++) {
            let res = this.castRes[this.rays.length - i - 1];
            const maxLength = dist(0, 0, this.sceneW, this.sceneH);

            const brightness = map(pow((maxLength - res) / maxLength, 2) * maxLength, 0, maxLength, 0, 255);
            const height = map(res, 0, maxLength, 0, this.sceneH * 0.45);

            fill(brightness);
            noStroke();
            rect(this.sceneW / this.castRes.length * i, height,
                 this.sceneW / this.castRes.length + 1, this.sceneH - height * 2);
        }
    }
}
