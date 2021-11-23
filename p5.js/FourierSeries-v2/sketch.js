const N = 50;

let cnt = 0;
let angle = 0;
const offset = 0.001;

const scale = 120;

let curve = [];
const speed = 0.5;

let fourierY = new Fourier();
let fourierX = new Fourier();

const xx = 500, xy = 150;
const yx = 150, yy = 500;
const cx = 500, cy = 500;

function setup() {
    createCanvas(800, 800);
    fourierX.buildSeries(N, function kernel(x) {
        return Complex(cos(2 * PI * x * 7), 0);
    });
    fourierY.buildSeries(N, function kernel(x) {
        return Complex(0, sin(2 * PI * x * 11));
    });
}

function draw() {
    background(0);

    let series = fourierX.getSeries(angle);
    let x = displayFourier(series, xx, xy).re;

    series = fourierY.getSeries(angle);
    let y = displayFourier(series, yx, yy).im;

    stroke(150);
    strokeWeight(1);
    line(xx + x, xy, cx + x, cy + y);
    line(yx, yy + y, cx + x, cy + y);

    curve.push({x, y});
    translate(cx, cy);

    stroke(255, 255, 50);
    strokeWeight(2);
    drawCurve(curve);

    stroke(255);
    strokeWeight(4);
    point(x, y);

    angle += offset;
    if (angle >= 1) {
        angle = 0;
        cnt += 1;
        curve = [];
    }
}

function displayFourier(series, x, y) {
    translate(x, y);
    let prev = Complex(0, 0);
    let now = Complex(0, 0);

    for (let i = 0; i < series.length; i += 1) {
        now = now.add(series[i].mul(scale).conjugate())

        stroke(255);
        strokeWeight(4);
        point(prev.re, prev.im);

        strokeWeight(1);
        line(prev.re, prev.im, now.re, now.im);

        noFill();
        ellipse(prev.re, prev.im, series[i].abs() * scale * 2);

        prev = now;
    }
    translate(-x, -y);

    return now;
}

function drawCurve(curve) {
    noFill();
    beginShape();
    for (let i = 0; i < curve.length; i ++) {
        curveVertex(curve[i].x, curve[i].y);
    }
    endShape();
}

// kernel list

// if (x - floor(x) >= 0.5) {
//     return -16 * (x - 0.75) * (x - 0.75) + 1;
// } else {
//     return ceil(x) - 2 * x;
// }

// return (round(x * 4) % 2) * 2 - 1;
