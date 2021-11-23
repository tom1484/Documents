class Fourier {
    constructor() {}

    func(angle, n) {
        let phi = 2 * PI * n * angle;
        return Complex(cos(phi), sin(phi)).mul(this.kernel(angle));
    }

    getx(n, from, to, step) {
        let s = Complex(0, 0);
        for (let i = from; i <= to; i += step) {
            s = s.add(this.func(i, n));
        }
        s = s.mul(step);

        return {
            scale: sqrt(s.re * s.re + s.im * s.im),
            offset: atan2(s.im, s.re) + HALF_PI
        };
    }

    getTest(n, from, to, step) {
        let s = Complex(0, 0);
        for (let i = from; i <= to; i += step) {
            s = s.add(this.func(i, n));
        }
        return s.mul(step);
    }

    build(N, kernel) {
        this.N = N;
        this.x = [];
        this.kernel = kernel;
        for (let i = 0; i <= this.N; i ++) {
            this.x[i] = this.getx(-i, 0, 1, 0.001);
        }
    }

    getValue(angle) {
        let val = 0;
        for (let i = 0; i <= this.N; i ++) {
            let phi = 2 * PI * i * angle + this.x[i].offset;
            val += this.x[i].scale * sin(phi);
        }
        return val;
    }
}
