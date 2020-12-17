/*
    traverse the array like a wave.
    top to bottom
    take a right
    bottom to top 
    take a left 
    ....
    repeat.

    input:

    1 6 7 12
    2 5 8 11
    3 4 9 10

    output:
    1 2 3 4 5 6 7 8 9 10 11 12

*/
#include <iostream>
using namespace std;

void wavePrint(int *arr[], int m, int n) {
    for(int j = 0; j < n; j++) {
        if(j & 1) {
            for(int i = m - 1; i >= 0; i--)
                cout << arr[i][j] << " ";
        }
        else {
            for(int i = 0; i < m; i++)
                cout << arr[i][j] << " ";
        }
    }
}

int main() {

    int m, n;
    cin >> m >> n;

    int *arr[m]; // array of pointer where each pointer would point to a dynamic array of size n.
    for(int i = 0; i < m; i++)
        arr[i] = new int[n];
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    wavePrint(arr, m, n);

    return 0;
}
    
