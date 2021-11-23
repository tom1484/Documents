let field = new Field();
let ball = new Ball();
let options;

function setup() {
    createCanvas(800, 800);

    let kernel = function kernel(x, y) {
        return createVector(
            sin(2 * PI * y),
            sin(2 * PI * x)
        );
        // return createVector(x, y);
    }
    field.initialize(800, 800, kernel);

    options = {
        timeStep: 0.1,
        position: createVector(
            random(800), random(800)
        ),
        mass: 1
    };
    ball.initialize(options);
}

function draw() {
    background(0);
    field.showArrows(20, 20, 6);

    ball.show();
    ball.applyForce(field.getForce(ball.position));
    ball.update();

    if (ball.position.x <= 0 || ball.position.y <= 0 ||
        ball.position.x >= width || ball.position.y >= height) {
        ball.setPosition(createVector(
            random(800), random(800)
        ));
        ball.setVolocity(
            createVector(0, 0)
        );
        ball.setAccelaration(
            createVector(0, 0)
        );
    }
}
