class Fourier {
    constructor() {
        this.x = [];
    }

    func(angle, n) {
        let phi = 2 * PI * n * angle;
        return Complex(cos(phi), sin(phi)).mul(this.kernel(angle));
    }

    getx(n, from, to, step) {
        let s = Complex(0, 0);
        for (let i = from; i <= to; i += step) {
            s = s.add(this.func(i, n));
        }
        return s.mul(step);
    }

    buildSeries(N, kernel) {
        this.N = N;
        this.kernel = kernel;
        // for (let i = 0; i <= this.N; i += 1) {
        //     this.x[i] = this.getx(-i, 0, 1, 0.001);
        // }
        for (let i = 0; i <= 2 * this.N; i += 1) {
            this.x[i] = this.getx(this.N - i, 0, 1, 0.001);
        }
    }

    getSeries(angle) {
        this.series = [];
        for (let i = 0; i <= this.N; i ++) {
            // let phi = 2 * PI * i * angle;
            // this.series[i] = this.x[i].mul(Complex(cos(phi), sin(phi)));
            if (i != 0) {
                let phi = 2 * PI * i * angle;
                this.series[2 * i - 1] = Complex(cos(phi), sin(phi)).mul(this.x[this.N + i]);
            }
            let phi = 2 * PI * -i * angle;
            this.series[2 * i] = Complex(cos(phi), sin(phi)).mul(this.x[this.N - i]);
        }
        return this.series;
    }
}
