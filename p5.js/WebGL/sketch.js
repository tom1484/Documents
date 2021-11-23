let angle = 45;

function setup() {
    createCanvas(800, 800, WEBGL);
}

function draw() {

    let dx = mouseX - width / 2;
    let dy = mouseY - height / 2;
    let v = createVector(dx, dy, 100);

    ambientLight(100, 0, 0);
    directionalLight(0, 0, 200, 400, 0, -50);
    pointLight(0, 255, 0, v);

    background(150);

    rotateX(angle);
    rotateY(angle * 0.9);
    rotateZ(angle * 1.3);

    // normalMaterial(100);
    specularMaterial(255);
    // ambientMaterial(100);
    noStroke();

    torus(150, 30, 50, 50);

    angle += 0.05;
}
