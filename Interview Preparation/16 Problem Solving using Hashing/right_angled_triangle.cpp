/*
    Given n points in a 2D cartesian plane, how many right angled triangles are there such that
    perpendicular or base is parallel to x or y axis ?
*/
#include <iostream>
#include <unordered_map>
using namespace std;
 
int rightTriangle(int **arr, int n) {
    // hash map to store count of points with same x, y coordinates
    unordered_map<int, int> same_x;
    unordered_map<int, int> same_y;

    for(int i = 0; i < n; i++) {
        same_x[arr[i][0]]++;
        same_y[arr[i][1]]++;
    }

    int count = 0;

    for(int i = 0; i < n; i++) {
        if(same_x[arr[i][0]] >= 1 and same_y[arr[i][1]] >= 1) {
            count += (same_x[arr[i][0]] - 1) * (same_y[arr[i][1]] - 1);
        }
    }
    return count;
}
 
int main() {
 
    int n;
    cin >> n;
    int **arr = new int*[n];

    for(int i = 0; i < n; i++) {
        arr[i] = new int[2];
        for(int j = 0; j < 2; j++)
            cin >> arr[i][j];
    }

    cout << rightTriangle(arr, n) << endl;
 
    return 0;
}