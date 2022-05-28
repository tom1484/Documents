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

    float dot(Vector V) {
        return this->x * V.x + this->y * V.y + this->z * V.z;
    }

	Vector operator* (float C) {
		return Vector(this->x * C, this->y * C, this->z * C);
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

const int N = 50;

vector<Point> points;
char projection[N][N] = {};

void generate_points();
void clear_projection();
void project_points();

// ======================================================================

float b_range = 11.9;
string b_table = ".,-~:;=!*#$@";

// ======================================================================

Vector light(0, -1, -1);

Point eye(0, 0, 400);
Point screen(0, 0, 300);
Vector screen_x(1, 0, 0);
Vector screen_y(0, 1, 0);
/* Point eye(400, 0, 0); */
/* Point screen(300, 0, 0); */
/* Vector screen_x(0, 1, 0); */
/* Vector screen_y(0, 0, 1); */

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

    generate_points();
    transformation.identify();

    Matrix xrot = generate_xrot(TPI / 200);
    Matrix yrot = generate_yrot(TPI / 300);
    Matrix zrot = generate_zrot(TPI / 400);

    while (true) {
        transformation = xrot * transformation;
        transformation = yrot * transformation;
        transformation = zrot * transformation;

        clear_projection();
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

    FOR (i, 0, N) {
        FOR (j, 0, N)
            cout << projection[i][j] << ' ';
        cout << '\n';
    }

    frame += 1;
    /* cout << frame << '\n'; */

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
            return (A - eye).norm() > (B - eye).norm();
         });

    Vector pivot = screen - eye;

    Vector V, proj_V;
    Point proj_P;

    float K;
    int x, y, brightness;

    for (Point P: t_points) {
        V = P - eye;
        if (V.z == 0)
            continue;

        K = pivot.norm() / (pivot.dot(V) / pivot.norm());
        proj_P = eye + (V * K);
		proj_V = proj_P - screen;

        x = (int)(proj_V.dot(screen_x) / screen_x.norm()) + (N / 2);
        y = -(int)(proj_V.dot(screen_y) / screen_y.norm()) + (N / 2);
        if (x < 0 || x >= N || y < 0 || y >= N)
            continue;

        brightness = (int)((-1) * b_range * light.dot(P.n_vector) / (light.norm() * P.n_vector.norm()));
        if (brightness < 0)
            brightness = 0;
        projection[y][x] = b_table[brightness];
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

void clear_projection() {

    FOR (i, 0, N)
        FOR (j, 0, N)
            projection[i][j] = ' ';
    cout.flush();

}

// ======================================================================

Matrix generate_xrot(float t) {

    Matrix M = Matrix();
    float T[3][3] = {
        {1, 0, 0},
        {0, (float)cos(t), (float)-sin(t)},
        {0, (float)sin(t), (float)cos(t)}
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
        {(float)cos(t), 0, (float)sin(t)},
        {0, 1, 0},
        {(float)-sin(t), 0, (float)cos(t)}
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
        {(float)cos(t), (float)-sin(t), 0},
        {(float)sin(t), (float)cos(t), 0},
        {0, 0, 1}
    };

    FOR (i, 0, 3)
        FOR (j, 0, 3)
            M.m[i][j] = T[i][j];

    return M;
}






