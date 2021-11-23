class Ball {
    contructor() {}

    initialize(options) {
        this.timeStep = options.timeStep || 1;
        this.position = options.position || createVector(0, 0);
        this.volocity = options.volocity || createVector(0, 0);
        this.accelration = options.accelration || createVector(0, 0);
        this.mass = options.mass || 1;
    }

    setPosition(position) {
        this.position = position;
    }

    setVolocity(volocity) {
        this.volocity = volocity;
    }

    setAccelaration(accelration) {
        this.accelration = accelration;
    }

    applyForce(force) {
        this.accelration = force.div(this.mass);
    }

    update() {
        this.position.add(
            this.volocity.copy().mult(this.timeStep)
        );
        this.volocity.add(
            this.accelration.copy().mult(this.timeStep)
        );
    }

    show() {
        noStroke();
        fill(255);
        circle(this.position.x, this.position.y, 10);
    }
}
