const N = 200;

let cnt = 0;
let angle = 0;
const offset = 0.001;

const scale = 360;

let curve = [];
const speed = 1;

let fourier = new Fourier();

function setup() {
    createCanvas(1200, 800);
    fourier.build(N, function kernel(x) {
        return (round(x * 4) % 2 - 0.5) * 2;
        // return 1 / cos(3 * x);
        // return sin(2 * PI * x * 5);
    });
}

function draw() {
    background(0);
    translate(200, 400);

    let transVal = fourier.getValue(angle);
    curve.unshift(transVal);

    stroke(255, 255, 0);
    strokeWeight(2);
    drawCurve(curve);

    if (curve.length * speed > 800) {
        curve.splice(curve.length - 1, 1);
    }

    angle += offset;
    if (angle >= 1) {
        angle = 0;
    }
}

function drawCurve(curve) {
    noFill();
    beginShape();
    for (let i = 0; i < curve.length; i ++) {
        vertex(i * speed, -curve[i] * scale);
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
