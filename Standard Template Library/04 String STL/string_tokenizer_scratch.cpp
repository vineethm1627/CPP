#include <iostream>
#include <cstring> // for strlen
using namespace std;

// use dynamic variable to store the entire array.
// in each function get the next token.
// keep a static variable to keep track of the token to be assigned.
// given an input string break it about the delimiter.

char *mystrtok(char *str, char delim) {
    // inputs string and a single char as a delimiter
    // static variables are initialized only once during the function call.
    // in the subsequent calls it used the same saved state as in the previous function call.
    static char* input = NULL; // will point to first token for first function call ie. str != NULL.
    if(str != NULL) {
        // we are making the first function call
        input = str; // ie. the static pointer will point to the beginning of the input string.
    }
    // check here  - base case after the final token has been returned
    if(input == NULL) {
        return NULL;
    }

    // start extracting tokens and store them in an array.
    // use dynamic array to store the tokens as we want the memory to stay intact for the next function call.
    char *output = new char[strlen(input) + 1];
    int i = 0;
    for(; input[i] != '\0'; i++) {
        if(input[i] != delim) {
            output[i] = input[i];
        }
        else {
            output[i] = '\0';
            input = input + i + 1;
            return output; // first token and there on next tokens
        }
    }

    // last token, there won't be any space for delim
    output[i] = '\0';
    input = NULL;
    return output;

}

int main() {

    char s[100] = "Today is a rainy day";
    char *ptr = mystrtok(s, ' ');
    cout << ptr << endl;

    while(ptr != NULL) {
        ptr = mystrtok(NULL, ' ');
        cout << ptr << endl;
    }

    return 0;
}