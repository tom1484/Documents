class Fourier {
    constructor() {
        this.x = [];
    }

    func(angle, n) {
        let phi = 2 * PI * n * angle;
        let k = this.kernel(angle);
        let re = cos(phi) * k.re - sin(phi) * k.im;
        let im = cos(phi) * k.im + sin(phi) * k.re;
        // let res = Complex(0, phi).exp().mul(this.kernel(x));
        return {re, im};
    }

    getx(n, from, to, step) {
        let s = 0;
        for (let i = from; i <= to; i += step) {
            s += this.func(i, n).re;
        }
        return s * step;
    }

    buildSeries(N, kernel) {
        this.N = N;
        this.kernel = kernel;
        for (let i = 0; i <= this.N; i += 1) {
            this.x[i] = this.getx(-i, 0, 1, 0.001);
        }
    }

    getSeries(angle) {
        this.series = [];
        for (let i = 0; i <= this.N; i ++) {
            let phi = 2 * PI * -i * angle;
            let re = this.x[i] * cos(phi);
            let im = this.x[i] * sin(phi);
            this.series[i] = {re, im};
        }
        return this.series;
    }
}
