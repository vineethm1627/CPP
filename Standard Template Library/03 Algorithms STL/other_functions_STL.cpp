#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}

int main() {

    int a = 10, b = 20;
    cout << "a = " << a << " b = " << b << endl;

    swap(a, b);
    cout << "After swapping : ";
    cout << "a = " << a << " b = " << b << endl;

    cout << "Max : " << max(a, b) << endl;
    cout << "Min : " << min(a, b) << endl;

    vector<int> v{1, 2, 3, 4, 5};
    // reverse the first 3 elements
    reverse(v.begin(), v.begin() + 3);
    cout << "After reversing first 3 elements : ";
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // sort the vector in descending order.
    sort(v.begin(), v.end(), compare);
    cout << "Sorted in desc order : ";
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;

    // swapping the first and the last element of the vector.
    swap(v[0], v[v.size() - 1]);
    cout << "After swapping first and the last element : ";
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
    cout << "Size of the vector : " << v.size() << endl;
    // cout << v.end() - v.begin() << endl;

    // generate the next_permutation : 
    next_permutation(v.begin(), v.end());
    cout << "next_permutation : ";
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}