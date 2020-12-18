/* 
    Sumatrix sum query on a matrix
    q --> queries
    form of query --> tl_x, tl_y, br_x, br_y

    you need to find the sum of the sub-matrix that is represented by the given coordinates.
*/
#include <iostream>
using namespace std;

void prefixSum(int *arr[], int *aux[], int r, int c) {
    // copy the first column
    for(int i = 0; i < r; i++)
        aux[i][0] = arr[i][0];

    // do column wise sum
    for(int i = 0; i < r; i++) {
        for(int j = 1; j < c; j++) 
            aux[i][j] = arr[i][j] + aux[i][j - 1];
    } 

    // now do the row wise sum
    for(int i = 1; i < r; i++) {
        for(int j = 0; j < c; j++) 
            aux[i][j] += aux[i - 1][j];
    }
}

int sumQuery(int *aux[], pair<int, int> tl, pair<int, int> br) {
    int sum = aux[br.first][br.second];
    if(tl.first > 0)
        sum -= aux[tl.first - 1][br.second];
    if(tl.second > 0)
        sum -= aux[br.first][tl.second - 1];
    if(tl.first > 0 and tl.second > 0)
        sum += aux[tl.first - 1][tl.second - 1];

    return sum;
}

int main() {

    int r, c;
    cin >> r >> c;

    int *arr[r];
    int *aux[r];
    for(int i = 0; i < r; i++) { 
        arr[i] = new int[c];
        aux[i] = new int[c];
    }
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cin >> arr[i][j];
    }

    int q;
    pair<int, int> tl, br;
    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> tl.first >> tl.second >> br.first >> br.second;
        prefixSum(arr, aux, r, c);
        cout << sumQuery(aux, tl, br) << endl;
    }

    return 0;
}