/* 
   print the following pattern
   if n = 5
   
   ABCDE
   ABCD
   ABC
   AB
   A
*/
#include <iostream>
using namespace std;

void pattern(int n) {
    char ch;
    for(int i = n; i >= 1; i--) {
        ch = 'A';
        for(int j = 1; j <= i; j++) {
            cout << ch;
            ch++;
        }
        cout << endl;
    }
}

int main() {

    int n;
    cin >> n;

    pattern(n);

    return 0;
}