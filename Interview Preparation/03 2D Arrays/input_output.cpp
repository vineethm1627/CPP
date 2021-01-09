#include <iostream>
#include <vector>
using namespace std;

// method1: array of pointers
void printArrayPointer(int *arr[], int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// method2: pointer to pointer
void printPointerPointer(int **arr, int r, int c) {
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

// method3: using 2d vector
void printVector(vector<vector<int>> &arr) {
    for(int i = 0; i < arr.size(); i++) {
        for(int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}

int main() {

    int r, c;
    cin >> r >> c;

    // method1: array of pointers
    int *arr1[r]; 
    for(int i = 0; i < r; i++)
        arr1[i] = new int[c];

    // method2: pointer to pointer
    int **arr2 = new int*[r]; 
    for(int i = 0; i < r; i++)
        arr2[i] = new int[c];

    // method3: 2d vector
    vector<vector<int>> arr3(r, vector<int>(c));

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++)
            cin >> arr1[i][j];
    }

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            arr2[i][j] = arr1[i][j];
    }

    for(int i = 0; i < arr3.size(); i++) {
        for(int j = 0; j < arr3[i].size(); j++)
            arr3[i][j] = arr2[i][j];
    }

    printArrayPointer(arr1, r, c);
    cout << "--------------------------\n";
    printPointerPointer(arr2, r, c);
    cout << "--------------------------\n";
    printVector(arr3);

    return 0;
}
