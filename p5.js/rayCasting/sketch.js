const canvasW = 1200;
const canvasH = 600;

const sceneW = 600;
const sceneH = 600;

let rays = [];
let walls = [];
let source;

function setup() {
    createCanvas(1200, 600);
    // frameRate(100);

    for (let i = 0; i < 5; i ++) {
        let x1 = random(0, sceneW), y1 = random(0, sceneH);
        let x2 = random(0, sceneW), y2 = random(0, sceneH);
        walls[i] = new boundary(x1, y1, x2, y2);
    }

    walls.push(new boundary(0, 0, sceneW, 0));
    walls.push(new boundary(sceneW, 0, sceneW, sceneH));
    walls.push(new boundary(sceneW, sceneH, 0, sceneH));
    walls.push(new boundary(0, sceneH, 0, 0));

    source = new particle(50, 50, 150, 0.1, -90);
    source.setScene(sceneW, sceneH);
}

function draw() {
    background(0);

    source.setPos(mouseX, mouseY);

    // if (keyIsDown(UP_ARROW)) {
    //     source.updatePos(0, -2);
    // }
    // if (keyIsDown(DOWN_ARROW)) {
    //     source.updatePos(0, 2);
    // }
    // if (keyIsDown(LEFT_ARROW)) {
    //     source.updatePos(-2, 0);
    // }
    // if (keyIsDown(RIGHT_ARROW)) {
    //     source.updatePos(2, 0);
    // }
    if (keyIsDown(122) || keyIsDown(90)) {
        source.updateDir(1);
    }
    if (keyIsDown(120) || keyIsDown(88)) {
        source.updateDir(-1);
    }

    for (let i = 0; i < walls.length; i ++) {
        walls[i].show();
    }

    source.cast(walls);
    source.show();

    translate(sceneW, 0);
    source.visualize();
}
