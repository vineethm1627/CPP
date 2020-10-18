#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    // similar to dictionary in python.
    pair<int, char> p;
    p.first = 10;
    p.second = 'b';

    // other way to initialize with already existing pair.
    pair<int, char>p1(p);
    cout << p1.first << " : " << p1.second << endl;

    // initialization using make_pair function
    pair<int, string> p2 = make_pair(1, "vineeth");
    cout << p2.first << " : " << p2.second << endl;

    int num1, num2;
    cout << "Enter 2 numbers : ";
    cin >> num1 >> num2;

    pair<int, int> p3 = make_pair(num1, num2);
    cout << p3.first << " : " << p3.second << endl;

    // pair of pair
    pair<pair<int, int>, string> car;
    car.second = "Audi";
    car.first.first = 10;
    car.first.second = 20;

    cout << car.first.first << " : " << car.first.second << " : " << car.second << endl;

    return 0;
}