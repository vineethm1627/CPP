/*
    multiset --> stores multiple duplicate elements.
    all elements are stored in a specific order.
    values once inserted cannot be modified.
    associative container ==> elements are referred by their value and not by index.
    underlying implementation uses BST.
*/
#include <iostream>
#include <set>
using namespace std;

typedef multiset<int>::iterator mit;

int main() {

    int arr[] = {10, 20, 30, 20, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    multiset<int> ms(arr, arr + n);

    // erase - 20
    ms.erase(20); // all occurrences will be removed

    // insert - 80
    ms.insert(80);

    // iterate
    for(int x: ms) 
        cout << x << " ";    
    cout << endl;
    // freq of occurrence
    cout << ms.count(10) << endl;

    auto it = ms.find(10);
    cout << *it << endl;

    // get all elements equal to 10
    pair<mit, mit> p = ms.equal_range(10);

    for(auto it = p.first; it != p.second; it++) 
        cout << *it << " ";

    cout << endl;
    // lower_bound and upper_bound
    for(auto it = ms.lower_bound(10); it != ms.upper_bound(10); it++)
        cout << *it << " ";


    return 0;
}