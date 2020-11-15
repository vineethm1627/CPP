/*
    You are standing at the origin (0, 0)
    there are various cabs around you with coordinates (xi, yi)
    
    approach:
        make a vector of pair. to store the location
        if you want to make the car name too, make a car class.
*/

// approach 1 : car name is not stored
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// custom comparator function
bool compare(pair<int, int> p1, pair<int, int> p2) {
    int d1 = pow(p1.first, 2) + pow(p1.second, 2);
    int d2 = pow(p2.first, 2) + pow(p2.second, 2);
    if(d1 == d2) {
        return p1.first < p2.first; // the car with lesser x coordinate
    }
    return d1 < d2; // sort in ascending order of distance from origin
}

int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        v.push_back(make_pair(x, y));
    }

    sort(v.begin(), v.end(), compare);
    cout << "sorted order : " << endl;
    for(auto p : v) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}