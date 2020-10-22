#include <iostream>
#include <cstring> // for using strlen function
using namespace std;

// using two pointer approach similar to pair_sum problem
bool isPalindrome(char p[]) {
    int i = 0, j = strlen(p) - 1;
    while(i < j) {
        if(p[i] == p[j]) {
            i++;
            j--;
        }
        else {
            return false;
        }
    }
    return true;
}

int main() {

    char p[1000]; // maxLen is 1000 characters ie. won't accept the input beyond 1000 character
    cout << "Enter the string : ";
    cin.getline(p, 1000); // default delim is '\n' so no need to specify.

    if(isPalindrome(p)) {
        cout << "Palindrome";
    }
    else {
        cout << "Not a palindrome";
    }
    
    return 0;
}