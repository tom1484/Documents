class controllPoint {
	constructor(x, y, r, c) {
		this.x = x;
		this.y = y;
		this.r = r;
		this.c = c; 		
	}

	show() {
		stroke(this.c);
		strokeWeight(this.r);
		point(this.x, this.y);
	}

	setPos(x, y) {
		this.x = x;
		this.y = y;
	}

	setRadius(r) {
		this.r = r;
	}

	setColor(c) {
		this.c = c;
	}
}