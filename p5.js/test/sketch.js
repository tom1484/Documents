let fourier = new Fourier();
let angle = 0;

let wave = [];

function setup() {
    createCanvas(800, 800);
    fourier.buildSeries(150, kernel);
}

function draw() {
    background(0);
    translate(400, 400);

    let series = fourier.getSeries(angle);
    // console.log(series[0]);

    let x = 0;
    let y = 0;
    for (let i = 0; i < series.length; i ++) {
        x += series[i].re * 100;
        y += series[i].im * 100;
    }
    wave.push({x, y});

    stroke(255);
    strokeWeight(2);
    noFill();
    beginShape();
    for (let i = 0; i < wave.length; i ++) {
        vertex(wave[i].x, wave[i].y);
    }
    endShape();

    angle += 0.001;
}

function kernel(x) {
    // if (x - floor(x) >= 0.5) {
    //     return -16 * (x - 0.75) * (x - 0.75) + 1;
    // } else {
    //     return ceil(x) - 2 * x;
    // }
    // return (round(x * 4) % 2) * 2 - 1;
    return Complex(0, sin(2 * PI * x * 17)).add(cos(2 * PI * x * 13));
    // return sin(2 * PI * x * 3);
    // return cos(2 * PI * x * 3);
}
