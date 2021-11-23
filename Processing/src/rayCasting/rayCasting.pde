import java.util.*;

int canvasW = 1200;
int canvasH = 600;

int sceneW = 600;
int sceneH = 600;

ArrayList <ray> rays = new ArrayList <ray>();
ArrayList <boundary> walls = new ArrayList <boundary>();
particle source;

boolean[] keys = {false, false, false, false, false, false};

void setup() {
    size(1200, 600);

    for (int i = 0; i < 5; i ++) {
      float x1 = random(0, sceneW), y1 = random(0, sceneH);
      float x2 = random(0, sceneW), y2 = random(0, sceneH);
      walls.add(new boundary(x1, y1, x2, y2));
    }

    walls.add(new boundary(-1, -1, sceneW + 1, -1));
    walls.add(new boundary(sceneW + 1, -1, sceneW + 1, sceneH + 1));
    walls.add(new boundary(sceneW + 1, sceneH + 1, -1, sceneH + 1));
    walls.add(new boundary(-1, sceneH + 1, -1, -1));

    source = new particle(50, 50, 100, 0.5, -90);
    source.setScene(sceneW, sceneH);
}

void keyPressed() {
    if (keyCode == UP)
        keys[0] = true;
    if (keyCode == DOWN)
        keys[1] = true;
    if (keyCode == LEFT)
        keys[2] = true;
    if (keyCode == RIGHT)
        keys[3] = true;
    if (keyCode == 'z' || keyCode == 'Z')
        keys[4] = true;
    if (keyCode == 'x' || keyCode == 'X')
        keys[5] = true;
}

void keyReleased() {
    if (keyCode == UP)
        keys[0] = false;
    if (keyCode == DOWN)
        keys[1] = false;
    if (keyCode == LEFT)
        keys[2] = false;
    if (keyCode == RIGHT)
        keys[3] = false;
    if (keyCode == 'z' || keyCode == 'Z')
        keys[4] = false;
    if (keyCode == 'x' || keyCode == 'X')
        keys[5] = false;
}

void draw() {
    background(0);

    if (keys[0]) {
      source.updatePos(0, -2);
    }
    if (keys[1]) {
      source.updatePos(0, 2);
    }
    if (keys[2]) {
      source.updatePos(-2, 0);
    }
    if (keys[3]) {
      source.updatePos(2, 0);
    }
    if (keys[4]) {
      source.updateDir(1);
    }
    if (keys[5]) {
      source.updateDir(-1);
    }

    for (int i = 0; i < walls.size(); i ++) {
      walls.get(i).show();
    }

    source.cast(walls);

    translate(sceneW, 0);
    source.visualize();
}
