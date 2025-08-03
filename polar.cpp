#include <bits/stdc++.h>

#define M_PI 3.14159265358979323846
using namespace std;
class Polar {
private:
    double r;
    double a;
public:
    Polar() : r(0), a(0) {}
    Polar(double radius, double angle) {
        r = radius;
        a = angle;
    }
    void toRectangular(double &x, double &y) const {
        x = r * cos(a);
        y = r * sin(a);
    }
    Polar operator+(const Polar &p) {
        double x1, y1, x2, y2;
        toRectangular(x1, y1);
        p.toRectangular(x2, y2);
        double x = x1 + x2;
        double y = y1 + y2;

        double new_r = sqrt(x * x + y * y);
        double new_a = atan(y/x)*57.29577;
        return Polar(new_r, new_a);
    }
    void display() const {
        cout << "Radius: " << r << ", Angle (in degree): " << a << endl;
    }
};
int main() {
    Polar p1(5, M_PI / 4);
    Polar p2(3, M_PI / 6);
    Polar result = p1 + p2;
    cout << "Result after addition:" << endl;
    result.display();
    return 0;
}
