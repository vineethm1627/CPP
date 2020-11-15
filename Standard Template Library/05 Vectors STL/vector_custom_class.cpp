/*
    You are standing at the origin (0, 0)
    there are various cabs around you with coordinates (xi, yi)
    
    approach:
        make a vector of pair. to store the location
        if you want to make the car name too, make a car class.

        string, vector and custom class.
*/

// approach 2 : car name is also stored
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

// custom comparator function
class Car {
    public:
        string name;
        int x, y;

        Car() {

        }

        Car(string n, int x, int y) {
            name = n;
            this->x = x;
            this->y = y;
        }

        int distance() {
            return pow(x, 2) + pow(y, 2);
        }

};

bool compare(Car a, Car b) {
    int d1 = a.distance();
    int d2 = b.distance();

    if(d1 == d2) {
        return a.name < b.name; // lexographic comparison
    }
    return d1 < d2;
}

int main() {

    int n;
    cin >> n;
    string name;
    // vector of custom class
    vector<Car> v;
    
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> name;
        cin >> x >> y;
        Car c(name, x, y);
        v.push_back(c);
    }

    sort(v.begin(), v.end(), compare);
    cout << "sorted order : " << endl;
    for(auto c : v) {
        cout << c.name <<  " " << c.x << " " << c.y << " " << " : " << c.distance() << endl;
    }

    return 0;
}