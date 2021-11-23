#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>

#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define RFOR(i, a, b) for (int i = a; i > b; --i)

#define pb push_back
#define mp make_pair
#define ft first
#define sd second

#define PI 3.14159265358979323846264338327
#define TPI 6.28318530717958647692528676655

#define INF numeric_limits<double>::infinity()

// ======================================================================

struct Point;
struct Vector;
struct Matrix;

struct Vector {
    float x, y, z;

    Vector(): x(0), y(0), z(0) {}
    Vector(float x, float y, float z):
        x(x), y(y), z(z) {}

    float norm() {
        return sqrt(this->x * this->x +
                    this->y * this->y +
                    this->z * this->z);
    }

    void normalize() {
        float K = this->norm();
        this->x /= K;
        this->y /= K;
        this->z /= K;
    }

    float dot(Vector V) {
        return this->x * V.x + this->y * V.y + this->z * V.z;
    }

	Vector operator* (float C) {
		return Vector(this->x * C, this->y * C, this->z * C);
	}

	void operator*= (float C) {
		this->x = this->x * C;
		this->y = this->y * C;
		this->z = this->z * C;
	}

	Vector operator/ (float C) {
		return Vector(this->x / C, this->y / C, this->z / C);
	}

	void operator/= (float C) {
		this->x = this->x / C;
		this->y = this->y / C;
		this->z = this->z / C;
	}

};

// ======================================================================

struct Point {
    float x, y, z;
    Vector n_vector;

    Point(): x(0), y(0), z(0) {}
    Point(float x, float y, float z):
        x(x), y(y), z(z) {}

    Vector operator- (Point P) {
        return Vector(this->x - P.x,
                      this->y - P.y,
                      this->z - P.z);
    }

    Point operator+ (Vector V) {
        return Point(this->x + V.x,
                     this->y + V.y,
                     this->z + V.z);
    }
};

// ======================================================================

struct Matrix {
    float m[3][3] = {0};

    void identify() {

        FOR (i, 0, 3)
            this->m[i][i] = 1;

    }

    Vector operator* (Vector V) {
        return Vector(this->m[0][0] * V.x + this->m[0][1] * V.y + this->m[0][2] * V.z,
                      this->m[1][0] * V.x + this->m[1][1] * V.y + this->m[1][2] * V.z,
                      this->m[2][0] * V.x + this->m[2][1] * V.y + this->m[2][2] * V.z);
    }

    Point operator* (Point P) {

        Point tmp = Point(this->m[0][0] * P.x + this->m[0][1] * P.y + this->m[0][2] * P.z,
                          this->m[1][0] * P.x + this->m[1][1] * P.y + this->m[1][2] * P.z,
                          this->m[2][0] * P.x + this->m[2][1] * P.y + this->m[2][2] * P.z);
        tmp.n_vector = (*this) * P.n_vector;

        return tmp;
    }

    Matrix operator* (Matrix M) {

        Matrix R;
        FOR (i, 0, 3)
            FOR (j, 0, 3) {
                R.m[i][j] = 0;
                FOR (k, 0, 3)
                    R.m[i][j] += this->m[i][k] * M.m[k][j];
            }

        return R;
    }
};

// ======================================================================

struct Point_2D {
    int x, y;
    int brightness;

    Point_2D() {}
    Point_2D(float x, float y, float b):
        x(x), y(y), brightness(b) {}
};

// ======================================================================

struct Light {
    float range;
    string table;

    Vector dir;

    float get_brightness(Vector V) {
        float K = this->dir.dot(V) / (this->dir.norm() * V.norm());
        return -K * this->range;
    }
};

// ======================================================================

struct Camera {
    float angle;
    int width;

    Point pos;
    Vector dir, x, y;

    Point_2D capture(Point P, Light light) {
        Vector V = P - this->pos;
        if (V.norm() == 0)
            return Point_2D(INF, INF, 0);

        float K = pow(this->dir.norm(), 2) / this->dir.dot(V);
        Point pro_P = this->pos + (V * K);
		Vector pro_V = pro_P - (this->pos + this->dir);

        float x = (pro_V.dot(this->x) / this->x.norm());
        float y = (pro_V.dot(this->y) / this->y.norm());

        x = this->width * (x + 0.5);
        y = this->width * (y + 0.5);

        float brightness = light.get_brightness(P.n_vector);
        if (brightness < 0)
            brightness = 0;

        return Point_2D((int)x, (int)y, brightness);
    }
};

// ======================================================================

const int WIDTH = 50;

vector<Point> points;
vector<Point_2D> projections;
char screen[WIDTH][WIDTH] = {};

void generate_points();
void clear_screen();
void project_points();

// ======================================================================

Camera camera;
Light light;

void initialize();

// ======================================================================

Matrix transformation;

Matrix generate_xrot(float);
Matrix generate_yrot(float);
Matrix generate_zrot(float);

// ======================================================================

int frame = 0;
void display();

// ======================================================================

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	initialize();

    generate_points();
    transformation.identify();

    Matrix xrot = generate_xrot(TPI / 200);
    Matrix yrot = generate_yrot(TPI / 300);
    Matrix zrot = generate_zrot(TPI / 400);

    while (true) {
        transformation = xrot * transformation;
        transformation = yrot * transformation;
        transformation = zrot * transformation;

        clear_screen();
        project_points();

        display();
    }

    return 0;
}

// ======================================================================

void display() {

    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef __linux__
    system("clear");
    #endif

    for (Point_2D P: projections) {
        if (P.x < 0 || P.x >= WIDTH || P.y < 0 || P.y >= WIDTH)
            continue;
        screen[P.y][P.x] = light.table[P.brightness];
    }

    for (int i = WIDTH - 1; i >= 0; i --) {
        for (int j = 0; j < WIDTH; j ++) {
            cout << screen[i][j] << ' ';
        }
        cout << '\n';
    }

    frame += 1;
    cout << frame << '\n';

	cout << endl;
    usleep(25000);

}

// ======================================================================

void project_points() {

    vector<Point> t_points;
    for (Point P: points) {
        P = transformation * P;
        t_points.push_back(P);
    }

    sort(t_points.begin(), t_points.end(), [](Point &A, Point &B) {
            return (A - camera.pos).norm() > (B - camera.pos).norm();
         });

    projections.clear();
    for (Point P: t_points) {
        projections.push_back(camera.capture(P, light));
    }

}

// ======================================================================

void generate_points() {

    int n1 = 50, n2 = 200;

    float delta = TPI / n1;
    float r = 20, R = 50;

    Point C = Point(R + r, 0, 0);

    for (float t = 0; t < 2 * PI; t += delta) {
        points.push_back(Point(r * cos(t) + C.x,
                               C.y,
                               r * sin(t) + C.z));
        points[points.size() - 1].n_vector = Vector(cos(t), 0, sin(t));
    }

    delta = TPI / n2;

    Matrix T;
    T.identify();

    Matrix xrot = generate_zrot(delta);

    for (float t = 0; t < 2 * PI; t += delta) {
        T = xrot * T;

        FOR (i, 0, n1) {
            points.push_back(T * points[i]);
            points[points.size() - 1].n_vector = T * points[i].n_vector;
        }
    }

}

// ======================================================================

void initialize() {

    camera.angle = PI / 3;

    camera.width = WIDTH;

    camera.dir = Vector(0, 0, -1);
    camera.pos = Point(0, 0, 400);
    camera.x = Vector(1, 0, 0);
    camera.y = Vector(0, 1, 0);

    camera.x.normalize();
    camera.y.normalize();
    camera.dir.normalize();
    camera.dir /= tan(camera.angle / 2);

    light.dir = Vector(0, -1, -1);

    light.range = 11.9;
    light.table = ".,-~:;=!*#$@";

}

// ======================================================================

void clear_screen() {

    for (int i = 0; i < WIDTH; i ++) {
        for (int j = 0; j < WIDTH; j ++) {
            screen[i][j] = ' ';
        }
    }
    cout.flush();

}

// ======================================================================

Matrix generate_xrot(float t) {

    Matrix M = Matrix();
    float T[3][3] = {
        {1, 0, 0},
        {0, cos(t), -sin(t)},
        {0, sin(t), cos(t)}
    };

    FOR (i, 0, 3)
        FOR (j, 0, 3)
            M.m[i][j] = T[i][j];

    return M;
}

// ======================================================================

Matrix generate_yrot(float t) {

    Matrix M = Matrix();
    float T[3][3] = {
        {cos(t), 0, sin(t)},
        {0, 1, 0},
        {-sin(t), 0, cos(t)}
    };

    FOR (i, 0, 3)
        FOR (j, 0, 3)
            M.m[i][j] = T[i][j];

    return M;
}

// ======================================================================

Matrix generate_zrot(float t) {

    Matrix M = Matrix();
    float T[3][3] = {
        {cos(t), -sin(t), 0},
        {sin(t), cos(t), 0},
        {0, 0, 1}
    };

    FOR (i, 0, 3)
        FOR (j, 0, 3)
            M.m[i][j] = T[i][j];

    return M;
}






