#include <iostream>
#include <cstring>
using namespace std;
 
int stringToInt(char *arr, int n) {
    // base case
    if(n == 0)
        return 0;
    
    int digit = arr[n - 1] - '0';
    int small_ans = stringToInt(arr, n - 1);

    return small_ans * 10 + digit;
}
 
int main() {
    
    char arr[] = "1234";
    int len = strlen(arr);

    int x = stringToInt(arr, len);
    cout << x << endl;
 
    return 0;
}