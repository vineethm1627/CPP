/*
    used to store unique collection of elements.
    Set elements are ordered in nature.
    It uses Red Black tree as its underlying data structure.  

    The common operations take O(logn) time.
    You can't update the elements.
    Remove the old element and push the new element in the set.
*/
#include <iostream>
#include <set>
using namespace std;

int main() {

    int arr[] = {10, 20, 11, 9, 8, 11, 10, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    set<int> s;
    for(int i = 0; i < n; i++) 
        s.insert(arr[i]);
    
    // removing an element
    s.erase(10);
    auto it = s.find(20);
    s.erase(it);
    
    for(set<int>::iterator it = s.begin(); it != s.end(); it++) 
        cout << *it << " ";
    cout << endl;

    return 0;
}
