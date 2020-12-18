/*  
    Approach
        Every element will be a part of more than one submatrix.
        In each matrix the element will be contributing for the sum.
        We just need the contribution of each cell / element in the total sum.
        sum the contribution of all the cells and find the total sum.

    contribution = cell value * (num of submatrices the cell is a part of).

*/
#include <iostream>
using namespace std;

int subMatricesSum(int **arr, int r, int c) {
    int sum = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            int tl_candidates = (i + 1)*(j + 1);
            int br_candidates = (r - i)*(c - j);
            // taking pnc of tl and br to obtain count of all matrices enclosing (i,j)
            int part_of_submatrices = tl_candidates * br_candidates;
            sum += arr[i][j] * part_of_submatrices;
        }
    }
    return sum;
}

int main() {

    int r, c;
    cin >> r >> c;
    int **arr = new int*[r];
    for(int i = 0; i < r; i++)
        arr[i] = new int[c];
    
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) 
            cin >> arr[i][j];
    }

    cout << subMatricesSum(arr, r, c) << endl;

    return 0;
}