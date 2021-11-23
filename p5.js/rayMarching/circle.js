class circle {
    constructor(x, y, r, vel) {
        this.x = x, this.y = y;
        this.r = r;
        this.vel = vel;
    }

    show() {
        noFill();
        stroke(255);
        strokeWeight(4);
        ellipse(this.x, this.y, this.r * 2);
    }

    update() {
        if (this.x + this.vel.x - this.r < 0 || this.x + this.vel.x + this.r > width)
            this.vel.x *= -1;
        if (this.y + this.vel.y - this.r < 0 || this.y + this.vel.y + this.r > width)
            this.vel.y *= -1;
        this.x += this.vel.x;
        this.y += this.vel.y;
    }

    signedDistance(x, y) {
        return dist(this.x, this.y, x, y) - this.r;
    }
}
