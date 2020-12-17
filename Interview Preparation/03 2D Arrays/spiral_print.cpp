/*
    traverse the array along the border and keep decreasing the length.

    input:

     1  2  3  4  5
     14 15 16 17 6
     13 20 19 18 7
     12 11 10 9  8

    output:
    1 2 3 ...... 18 19 20
*/
#include <iostream>
using namespace std;

void spiralPrint(int *arr[], int m, int n) {
    int sr = 0, sc = 0;
    int er = m - 1, ec = n - 1;

    while(sr <= er and sc <= ec) {
        // start row
        for(int j = sc; j <= ec; j++)
            cout << arr[sr][j] << " ";
        sr++;

        // end column
        for(int i = sr; i <= er; i++)
            cout << arr[i][ec] << " ";
        ec--;

        // end row
        if(sr < er) {
            for(int j = ec; j >= sc; j--)
                cout << arr[er][j] << " ";
            er--;
        }
        // start column
        if(sc < ec) {
            for(int i = er; i >= sr; i--)
                cout << arr[i][sc] << " ";
            sc++;
        }
    }

}

int main() {

    int m, n;
    cin >> m >> n;

    int *arr[m];
    for(int i = 0; i < n; i++)
        arr[i] = new int[n];
    
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    spiralPrint(arr, m, n);

    return 0;
}