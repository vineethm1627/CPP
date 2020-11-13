/*
    read a list of characters (sentence)
    cin doesn't read from the screen, it reads from the input buffer
    space is a special character, cin doesn't read white spaces
    if in the input buffer : hello world
    cin wont read space
    after cin, cout will give helloworld

    to solve this issue, use cin.get()
*/
#include <iostream>
using namespace std;

int main() {

    char ch;
    // reads the first character
    ch = cin.get(); // reads a single character(including speical chars) from the input buffer
    while(ch != '.') {
        // print the last character being read
        cout << ch;
        // update my char in the memory by reading the next character
        //cin >> ch;
        ch = cin.get();
    }
    return 0;
}