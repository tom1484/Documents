class connection {
	constructor(p1, p2, width) {
		this.p1 = p1;
		this.p2 = p2;
		this.width = width;
	}

	show() {
		stroke(128);
		strokeWeight(this.width);
		line(this.p1.x, this.p1.y, this.p2.x, this.p2.y);
	}

	setWidth(width) {
		this.width = width;
	}
}