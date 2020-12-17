#include <iostream>
using namespace std;

int main() {

    int r, c;
    cin >> r >> c;
    char *arr[r];
    for(int i = 0; i < 5; i++) {
        arr[i] = new char[c];
    }

    for(int i = 0; i < r; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cout << arr[i][j];
        cout << endl;
    }

    return 0;
}