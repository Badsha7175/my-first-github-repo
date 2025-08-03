#include <iostream>
using namespace std;
class DB;
class DM {
    float meters;
    float centimeters;
public:
    DM() {
        meters = 0;
        centimeters = 0;
    }
    DM(float m, float cm) {
        meters = m;
        centimeters = cm;
    }
    void readDistance() {
        cout << "Enter distance in meters and centimeters:";
        cin >> meters >> centimeters;
    }
    void display() {
        cout << "Distance: " << meters << " meters " << centimeters << " centimeters\n";
    }
    friend DM add(const DM&, const DB&);
};

class DB {
    float feet;
    float inches;
public:
    DB() {
        feet = 0;
        inches = 0;
    }
    DB(float f, float in) {
        feet = f;
        inches = in;
    }
    void readDistance() {
        cout << "Enter distance in feet and inches:";
        cin >> feet >> inches;
    }
    void display() {
        cout << "Distance: " << feet << " feet " << inches << " inches\n";
    }
    friend DM add(const DM&, const DB&);
};
DM add(const DM& d1, const DB& d2) {
    float total_cm = d1.meters * 100 + d1.centimeters;
    float db_cm = (d2.feet * 12 + d2.inches) * 2.54;
    total_cm = total_cm + db_cm;
    float meters = (int)(total_cm / 100);
    float centimeters = (int)(total_cm) % 100;
    return DM(meters, centimeters);
}

int main() {
    DM dm;
    DB db;
    dm.readDistance();
    db.readDistance();
    DM result = add(dm, db);
    cout << "\nResult in meters and centimeters:\n";
    result.display();
    return 0;
}
