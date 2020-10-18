#include <iostream>
#include <algorithm>
#include <vector>
#include <climits> // for max and min init.
#include <cstdlib> // for random seeding
#include <time.h>
using namespace std;

int main() {
    // find the min and max element of the array. 
    int n = 7;
    vector<int> v;
    srand(time(0)); // generates a random seed everytime we run the code again.
   
    for(int i = 0; i < n; i++) {
        // to generate numbers from 0 to 100
        v.push_back(rand() % 100);
    }
    // init smallest --> + inf
    // init largest  --> - inf
    //int smallest = INT_MAX, largest = INT_MIN;
    /* for(int i = 0; i < n; i++) {
        if(v[i] > largest) {
            largest = v[i];
        }

        if(v[i] < smallest) {
            smallest = v[i];
        }
    }
    */

    // using STL :
    // dereferencing to get the element provided with the address where the element is stored.
    int smallest = *min_element(v.begin(), v.end());
    int largest = *max_element(v.begin(), v.end());
     

    cout << "Array : ";
    for(int i : v) {
        cout << i << " ";
    }
    cout << endl;
    
    cout << "Smallest : " << smallest << " Largest : " << largest << endl;
    return 0;
}