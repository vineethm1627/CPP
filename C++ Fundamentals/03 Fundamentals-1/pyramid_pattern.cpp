/*
    if n = 5, 
        1
       232
      34543
     4567654
    567898765   

    explanation: 
    for i = 1 ie the first line there are 2 * 1 - 1 = 1 element
    for i = 2 ie the second line there are 2 * 2 - 1 = 3 elements
    ...
    for ith line --> 2*i-1 elements.
    for ith line --> number of spaces = n - i
    each ith line begins with i and the value is incremented i times and the value then is decremented i - 1 times.
    
    ex: for second line i = 3, 3 4 5 : 4 3 ie value is incremented 3 times and decremented 2 times.
*/
#include <iostream>
using namespace std;

int main() {

    int n = 5;
    for(int i = 1; i <= n; i++) {
        // spaces
        for(int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // increasing sequence
        for(int j = i; j <= 2 * i - 1; j++) {
            cout << j;
        }
        // decreasing sequence
        for(int j = 2 * i - 2 ; j >= i; j--) {
            cout << j;
        }
        cout << endl;
    }
    return 0;
}