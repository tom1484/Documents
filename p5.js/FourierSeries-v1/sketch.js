let N = 150;

let cnt = 0;
let angle = 0;
let offset = 0.001;

let scaleRe = 300;
let scaleIm = 300;

let curve = [];

let fourier = new Fourier();

function setup() {
    createCanvas(800, 800);
    fourier.buildSeries(N, function kernel(x) {
        return Complex(cos(2 * PI * x * 13), sin(2 * PI * x * 17));
        // return Complex((floor(x * 4) % 2 - 0.5) * 2, 0);
        // return (floor(x * 4) % 2 - 0.5) * 2;
    });
}

function draw() {
    background(0);
    translate(400, 400);

    let series = fourier.getSeries(angle);

    let x = 0;
    let y = 0;
    let prev = {x, y};
    let now = {x, y};

    for (let i = 0; i < series.length; i += 1) {
        now.x = prev.x + series[i].re * scaleRe;
        now.y = prev.y + series[i].im * scaleIm;

        stroke(255);
        strokeWeight(1);
        line(prev.x, prev.y, now.x, now.y);

        prev.x = now.x;
        prev.y = now.y;
    }
    curve.push(now);

    strokeWeight(2);
    stroke(255, 255, 50);
    drawCurve(curve);

    angle += offset;
    if (angle >= 1) {
        angle = 0;
        cnt += 1;
        curve = [];
    }
}

function setN(n) {
    N = n;
    fourier.buildSeries(N, kernel);
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

// return (round(x * 4) % 2 - 0.5) * 2;
