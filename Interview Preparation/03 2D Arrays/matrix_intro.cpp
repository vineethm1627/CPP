#include <iostream>
using namespace std;

int main() {

    int arr[5][3] = {0}; // init with all 0s.

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            arr[i][j] = i + j;
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}