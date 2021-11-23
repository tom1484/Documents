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
		for (int i = 0; i < 3; i ++) {
			for (int j = 0; j < 3; j ++) {
				R.m[i][j] = 0;
				for (int k = 0; k < 3; k ++) {
					R.m[i][j] += this->m[i][k] * M.m[k][j];
				}
			}
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

Vector light(-1, 0, -1);

/* Point eye(0, 0, 200); */
/* Point screen(0, 0, 100); */
/* Vector screen_x(1, 0, 0); */
/* Vector screen_y(0, 1, 0); */
Point eye(200, 0, 0);
Point screen(100, 0, 0);
Vector screen_x(0, 1, 0);
Vector screen_y(0, 0, 1);

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

    system("clear");
    FOR (i, 0, N) {
		FOR (j, 0, N) {
            cout << projection[i][j] << ' ';
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
            return (A - eye).norm() > (B - eye).norm();
         });

    Vector pivot = screen - eye;

    Vector V, proj_V;
    Point proj_P;

    float K;
    int x, y, brightness;

    for (Point P: t_points) {
        V = P - eye;

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

    int n1 = 70, n2 = 30, n3 = 80;
    float R = 18, H = 35;

	for (int k = -1; k < 2; k += 2) {
		for (int i = 1; i < n1; i ++) {
			float K = (float)i / (n1 - 1);
			float r = R * K;

			for (float t = 0; t < TPI; t += TPI / (n1 * K)) {
				points.push_back(Point(r * cos(t), r * sin(t), k * H));
				points[points.size() - 1].n_vector = Vector(0, 0, k);
			}
		}
	}
	
	for (int i = 0; i < n3; i ++) {
		float K = (float)i / (n3 - 1);
		float h = H * (2.0 * i / (n3 - 1) - 1);

		for (float t = 0; t < TPI; t += TPI / n1) {
			points.push_back(Point(R * cos(t), R * sin(t), h));
			points[points.size() - 1].n_vector = Vector(cos(t), sin(t), 0);
		}
	}

}

// ======================================================================

void clear_projection() {

for (int i = 0; i < N; i ++) {
	for (int j = 0; j < N; j ++) {
		projection[i][j] = ' ';
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

for (int i = 0; i < 3; i ++) {
	for (int j = 0; j < 3; j ++) {
		M.m[i][j] = T[i][j];
	}
} 

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

for (int i = 0; i < 3; i ++) {
	for (int j = 0; j < 3; j ++) {
		M.m[i][j] = T[i][j];
	}
} 

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

for (int i = 0; i < 3; i ++) {
	for (int j = 0; j < 3; j ++) {
		M.m[i][j] = T[i][j];
	}
} 

return M;
}






