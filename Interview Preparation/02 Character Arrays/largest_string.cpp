#include <iostream>
#include <cstring>
using namespace std;

int main() {
    // read n, followed by n strings and print the largest string and its length
    // don't store all the strings
    // store the largest string till now and the current input string.
    int n;
    cin >> n;
    cin.get(); // fetches the '\n' after the integer n.
    // if you skip the above line the first string will fetch '\n' and hence you will obtain wrong results.3
    int len = 0, largest_len = 0;
    char a[1000], largest_a[1000];
    for(int i = 0; i < n; i++) {
        cin.getline(a, 1000);
        //cout << a << endl;
        len = strlen(a);
        if(len > largest_len) {
            largest_len = len;
            //largest_a = a; // error : invalid array assignment, instead use a for loop to copy char by char.
            strcpy(largest_a, a); // copies all the character of a into largest_a 
        }
    }

    cout << "largest array : " << largest_a << endl;
    cout << "length : " << largest_len << endl;
    return 0;
}