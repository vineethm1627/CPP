#include <iostream>
using namespace std;

// read a sentence/paragraph and store it.
// cin.get reads a single character.
// put a loop to read all the characters till you get a newline ie. '\n'
// an alternative to this function is to use cin.getline() function provided by C++.

void readline(char a[], int maxLen, char delim = '\n') {
    int i = 0;
    char ch = cin.get();
    while(ch != delim) {
        a[i++] = ch; // post increment ie. first use and then increment.
        if(i == (maxLen - 1)) {
            break;
        }
        ch = cin.get();
    }
    // use the last index to store the null character.
    a[i] = '\0';
}

int main() {

    // sentence input with '\n' as delimiter.
    char a[1000];
    cout << "Enter a sentence : ";
    readline(a, 1000); // custom function call.
    cout << "You entered : ";
    cout << a << endl;

    // paragraph input with custom delimiter.
    char delim;
    cout << "Enter a delimiter : ";
    cin >> delim;
    cout << "Enter a paragraph : " << endl;
    //readline(a, 1000, delim); // custom function call.
    cin.getline(a, 1000, delim); // inbuilt function call.
    cout << "You entered : ";
    cout << a << endl;

    return 0;
}