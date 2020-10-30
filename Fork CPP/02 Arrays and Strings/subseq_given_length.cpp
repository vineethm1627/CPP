
#include <iostream>
#include <cmath>
using namespace std;

int countSetBits(int num) {
    int count = 0;
    while(num) {
        count += (num & 1); // bitwise and with the last bit.
        num = num >> 1; // rightshift divides the number by 2 or removes the last bit or LSB
    }
    return count;
}

void findSubset(int arr[], int n, int len) {
    for(int i = 1; i < pow(2, n); i++) {
        if(len == countSetBits(i)) {
            for(int j = 0; j < n; j++) {    
                if(i & (1 << j)){
                    cout << arr[j] << " ";
                }
            }
            cout << endl;
        }
        
    }
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int len = 2;
    findSubset(arr, n, len);
    return 0;
}