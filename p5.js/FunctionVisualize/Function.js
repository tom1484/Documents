class Function {
    constructor(kernel) {
        this.kernel = kernel;
    }

    setPadding(width, length) {
        this.width = width;
        this.length = length;
    }

    show(minVal, maxVal, step, clr1, clr2, stk) {
        stroke(255);
        strokeWeight(1);
        line(0, 10, this.width, 10);
        line(0, this.length - 10, this.width, this.length - 10);

        for (let i = 1; i <= 9; i ++) {
            let x = map(i, 1, 9, 10, this.width - 10);
            line(x, 0, x, 20);
            line(x, this.length - 20, x, this.length);
        }

        for (let i = minVal; i <= maxVal; i += step) {
            let p1 = createVector(
                map(i, minVal, maxVal, 10, this.width - 10), 10
            );
            let p2 = createVector(
                map(this.kernel(i), minVal, maxVal, 10, this.width - 10),
                this.length - 10
            );

            let c = -1;
            if (p2.x > this.width) c = this.width;
            else if (p2.x < 0) c = 0;

            if (c != -1) {
                let r = abs((c - p1.x) / (p2.x - p1.x));
                p2.x = c;
                p2.y = p1.y + (p2.y - p1.y) * r;
            }

            let iter = map(i, minVal, maxVal, 0, 1);
            stroke(lerpColor(clr1, clr2, iter));
            strokeWeight(stk);
            line(p1.x, p1.y, p2.x, p2.y);
        }
    }
}
