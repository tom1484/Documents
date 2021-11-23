let points = [];
let P;
let connections = [];
let curve = [];

let pointTarget = -1;
let lineTarget = -1;
let mouseClick = false;
let dragging = false;

function setup() {
    createCanvas(800, 800);
    
    // points.push(new controllPoint(-width / 4, 0, 10, color(255)));
    // points.push(new controllPoint(0, height / 4, 10, color(255)));
    // points.push(new controllPoint(width / 4, 0, 10, color(255)));
    const pointsNum = 10;
    for (let i = 0; i < pointsNum; i ++) {
        points.push(new controllPoint(-width / 4 + 400 * (i / (pointsNum - 1)), 0, 10, color(255)));
    }
    for (let i = 1; i < points.length; i ++) {
        connections.push(new connection(points[i - 1], points[i], 2));
    }
}

function mouseClicked() {
    if (lineTarget >= 0) {
        
    }
}

function mouseDragged() {
    dragging = true;

    if (pointTarget >= 0 && 
        mouseX >= 0 && mouseX < width && 
        mouseY >= 0 && mouseY < height) {
        const newMouseX = mouseX - 400;
        const newMouseY = mouseY - 400;
        points[pointTarget].setPos(newMouseX, newMouseY);
    }
}

function mouseReleased() {
    dragging = false;
}

function draw() {
    background(0);
    translate(400, 400);

    const newMouseX = mouseX - 400;
    const newMouseY = mouseY - 400;

    let n = points.length;

    if (!dragging) {
        pointTarget = -1;
        lineTarget = -1;
        let minDis = 1e9;
        let d;
        for (let i = 0; i < n; i ++) {
            d = dist(newMouseX, newMouseY, points[i].x, points[i].y);
            if (d <= 10 && d < minDis) {
                minDis = d;
                if (pointTarget != -1) {
                    points[pointTarget].setRadius(10);
                }
                points[i].setRadius(15);
                pointTarget = i;
            }
            else points[i].setRadius(10);
        }
    }

    // if (!dragging && pointTarget == -1) {
    //     lineTarget = -1;
    //     let minDis = 1e9;
    //     let d1;
    //     let d2;
    //     for (let i = 0; i < n - 1; i ++) {
    //         d1 = linePointDist(
    //             createVector(newMouseX, newMouseY), 
    //             connections[i]);
            
    //         const L = connections[i];
    //         const length = dist(L.p1.x, L.p1.y, L.p2.x, L.p2.y);
    //         const a = -(L.p2.y - L.p1.y) / (L.p2.x - L.p1.x);
    //         const midX = (L.p1.x + L.p2.x) / 2;
    //         const midY = (L.p1.y + L.p2.y) / 2
    //         d2 = linePointDist(
    //             createVector(newMouseX, newMouseY), 
    //             new connection(
    //                 createVector(midX, midY), 
    //                 createVector(midX + a, midY + 1)));
            
    //         if (i == 1) console.log(d1, d2);

    //         if (d1 <= 4 && d2 <= length / 2)
    //             lineTarget = i;
    //     }
    // }

    n = points.length;
    P = points;

    connections = [];
    for (let i = 1; i < n; i ++) {
        connections.push(new connection(P[i - 1], P[i], 2));
    }

    curve = [];
    for (let t = 0; t <= 1; t += 0.01) {
        let B = createVector(0, 0);
        for (let i = 0; i < n; i ++) {
            const coefficient = 
            C(n - 1, i) * pow(t, i) * pow(1 - t, n - 1 - i);
            let tmpPoint = createVector(P[i].x, P[i].y);
            tmpPoint.mult(coefficient);
            B.add(tmpPoint);
        }
        curve.push(B);
    }

    noFill();
    stroke(255, 0, 0);
    strokeWeight(2);
    // beginShape();
    for (let i = 1; i < curve.length; i ++) {
        // curveVertex(curve[i].x, -curve[i].y);
        line(curve[i - 1].x, curve[i - 1].y, curve[i].x, curve[i].y);
    }
    // endShape();

    for (let i = 0; i < n - 1; i ++) {
        connections[i].show();
    }

    for (let i = 0; i < n; i ++) {
        P[i].show();
    }
}

function C(n, k) {
    let res = 1;
    let j = n - k;

    for (let i = k + 1; i <= n; i ++) {
        res *= i;
        while (res % j == 0) {
            res /= j;
            j --;
        }
    }

    return res;
}

function pow(n, e) {
    let b = n;
    let res = 1;

    while (e > 0) {
        if (e % 1)
            res *= b;
        b *= b;
        e >>= 2;
    }

    return res;
}

function linePointDist(P, L) {
    if (L.p2.x != L.p1.x) {
        let a = -(L.p2.y - L.p1.y) / (L.p2.x - L.p1.x);
        let b = -(L.p1.y - a * L.p1.x);
    
        return abs(a * P.x + P.y + b) / sqrt(a * a + 1);
    }
    else {
        return abs(P.x - L.p1.x);
    }
}