let func = new Function(function(x) {
    return sqrt(sin(cos(x)) + 1);
});

function setup() {
    createCanvas(1600, 600);
    func.setPadding(1500, 500);
}

function draw() {
    background(0);

    translate(50, 50);
    func.show(
        -6, 6, 0.01,
        color(255, 128, 0),
        color(255, 255, 0),
        0.3
    );
}
