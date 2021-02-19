/*
    There are n white dots and n black dots, equally spaced in a line.
    You want to connect each white dodt with some black dot with a min. length of wire.

    Find the total length of the wire needed.
*/
#include <iostream>
#include <algorithm>
using namespace std;

int minWire(int *white, int *black, int n) {
    // sort the arrays
    sort(white, white + n);
    sort(black, black + n);

    int total_len = 0;
    for(int i = 0; i < n; i++) 
        total_len = abs(white[i] - black[i]);

    return total_len;
}
 
int main() {
 
    int n;
    cin >> n;

    int white[n], black[n];
    for(int i = 0; i < n; i++)
        cin >> white[i];
    for(int i = 0; i < n; i++)
        cin >> black[i];
    
    cout << "min length of wire: " << minWire(white, black, n) << '\n';

    return 0;
}