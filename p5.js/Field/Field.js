class Field {
    constructor() {}

    initialize(width, height, kernel) {
        this.kernel = kernel;

        this.WIDTH = width;
        this.HEIGHT = height;

        this.FORCE = [];
        for (let i = 0; i <= this.WIDTH; i ++) {
            this.FORCE[i] = [];
            let x = map(i, 0, this.WIDTH, -1, 1);
            for (let j = 0; j <= this.HEIGHT; j ++) {
                let y = map(j, 0, this.HEIGHT, -1, 1);
                this.FORCE[i][j] = this.kernel(x, y);
            }
        }

    }

    getForce(pos) {
        let x = round(pos.x);
        let y = round(pos.y);

        return this.FORCE[x][y];
        // return this.BilinearInterpolation(pos.x, pos.y)
    }

    showArrows(xNum, yNum, size) {
        for (let i = 1; i <= xNum; i ++) {
            let x = round(map(i, 1, xNum, 0, this.WIDTH));
            for (let j = 1; j <= yNum; j ++) {
                let y = round(map(j, 1, yNum, 0, this.HEIGHT));
                let pos = createVector(x, y);
                this.drawArrow(pos, this.FORCE[x][y], size);
            }
        }
    }

    drawArrow(p, v, scale) {
        let angle = atan2(v.y, v.x);
        let length = sqrt(v.x * v.x + v.y * v.y);
        let c1 = color(255, 0, 0);
        let c2 = color(100, 255, 0);
        let inter = map(p.x + p.y, 0, this.WIDTH + this.HEIGHT, 0, 1);
        let clr = lerpColor(c1, c2, inter);

        push();
        translate(p.x, p.y);
        rotate(angle);

        noStroke();
        fill(clr);
        triangle(
            -1.5 * scale * length, -0.5 * scale * length,
            -1.5 * scale * length, 0.5 * scale * length,
            1.5 * scale * length, 0
        );
        pop();
    }

    // BilinearInterpolation(x, y) {
    //     let x1 = floor(x), x2 = ceil(x);
    //     let y1 = ceil(y), y2 = floor(y);
    //
    //     let m1 = [y2 - y, y - y1];
    //     let m2 = [[this.FORCE[x1][y1], this.FORCE[x1][y2]],
    //               [this.FORCE[x2][y1], this.FORCE[x2][y2]]];
    //
    //     let t = [m2[0][0].mult(m1[0]).add(m2[0][1].mult(m1[1])),
    //              m2[1][0].mult(m1[0]).add(m2[1][1].mult(m1[1]))];
    //     // console.log(t);
    //     let m3 = [x2 - x, x - x1];
    //
    //     let r = t[0].mult(m3[0]).add(t[1].mult(m3[1]));
    //     return r.div((x2 - x1) * (y2 - y1));
    // }

}
