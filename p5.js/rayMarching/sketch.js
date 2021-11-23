const INF = 1e9;

let myRay;
let stuff = [];
// let test = createVector(100, 100);

function setup() {
    createCanvas(800, 800);
    myRay = new ray(width / 2, height / 2, 0);

    for (let i = 0; i < 5; i ++) {
        const r = random(20, 100);
        const x = random(r, width - r);
        const y = random(r, height - r);
        const vel = p5.Vector.random2D();
        stuff.push(new circle(x, y, r, vel));
    }
}

function draw() {
    background(0);

    // myRay.show(50);
    for (let i = 0; i < stuff.length; i ++) {
        stuff[i].show();
        stuff[i].update();
    }

    myRay.march(stuff);

    myRay.rotate(1);
    // console.log(myRay.dir);
}
