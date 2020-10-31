#include <iostream>
#include <cmath>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while(num) {
        count += (num & 1);
        num = num >> 1;
    }
    return count;
}

void findSubset(int arr[], int n, int len) {
    for(int i = 1; i < pow(2, n); i++) {
        if(len == countSetBits(i)) {
            int temp = i, j = 0;
            while(temp) {
                if(temp & 1) {
                    cout << arr[j] << " ";
                }
                j++;
                temp = temp >> 1;
            }
            cout << endl;
        }
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int len;
    cin >> len;
    findSubset(arr, n, len);

    return 0;
}

