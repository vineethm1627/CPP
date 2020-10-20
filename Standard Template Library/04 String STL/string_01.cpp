#include <iostream>
#include <string>
using namespace std;

int main() {
    // string initializations

    string s0; // empty string object.
    string s1("hello"); // initialize.
    string s2 = "Hello"; // assignment
    string s3(s2); // calling the copy ctor.
    string s4 = s3;

    // init from an array
    char arr[] = {'a', 'b', 'c', 'd', 'e', '\0'}; // all strings must end with null character.
    string s5(arr);

    cout << s5 << endl;
    cout << "length : " << s5.length() << endl;

    if(s0.empty()) {
        cout << "s0 string is empty" << endl;
    }
    if(s5.empty()) {
        cout << "s5 string is empty" << endl;
    }
    else {
        cout << "s5 is not empty" << endl;
    }

    // appending characters in a string.
    s0.append("I love C++ ");
    cout << s0 << endl;

    s0 += "and Python"; // other way to append.
    cout << s0 << endl;

    cout << "current length : " << s0.length() << endl;
    s0.clear();
    cout << "after clearing : " << s0.length() << endl;
    
    s0 = "Apple";
    s1 = "Mango";
    // compares 2 strings
    /* 
        returns :
        0 --> strings are equal
        1 --> (> greater than)
       -1 --> (< less than)
    */
    cout << s0.compare(s1) << endl;

    // overloaded operators on string object
    cout << (s0 > s1) << endl;

    cout << "First character of Apple : " << s0[0] << endl;

    // finding substrings.
    string sub = "I want to bag 20 lakhs job";
    int idx = sub.find("to bag"); // returns 2.
    // returns -1 if the substring is not present.
    cout << "index : " << idx << endl;

    // remove a word from the string.
    string word = "to bag";
    // starting index, no. of characters to remove from the starting index
    sub.erase(idx, word.length() + 1); // +1 to remove the extra space after the word to be removed.

    cout << "after erasing : " << sub << endl;

    // iterate over all the characters in the string.
    for(int i = 0; i < sub.length(); i++) {
        cout << sub[i] << " ";
    }
    cout << endl;
    // using iterators
    // it.end() points to the position after the last element.
    // so it.end() - 1 points to the last element.
    // [it.begin(), it.end())

    for(auto it = sub.begin(); it < sub.end(); it++) {
        cout << *it << " ";
    }
    cout << endl;

    // enhanced for loop
    for(char c : sub) {
        cout << c << " ";
    }
    cout << endl;
    

    return 0;
}