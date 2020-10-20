#include <iostream>
#include <algorithm>
#include <string.h> // to make strtok work
using namespace std;

/*
 strtok returns a token on each subsequent call.
 on the first call, function should be passed with string argument for 's'.
 on subsequent calls, we should pass the string argument to the function as 'NULL'.
*/

int main() {
    // char *strtok(char *s, char *delimiter)
    char s[100] = "Today is a rainy day";

    // strtok maintains the state of the string.
    // character pointer pointing to the first token in the given string.
    char *ptr = strtok(s, " ");
    cout << ptr << endl; // prints Today
    /*
    ptr = strtok(NULL, " "); //prints is
    cout << ptr << endl;
    */
    
    while(ptr != NULL) {
        ptr = strtok(NULL, " ");
        cout << ptr << endl;
    }

    return 0;
}