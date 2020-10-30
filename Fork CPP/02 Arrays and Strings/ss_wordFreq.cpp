#include <iostream>
#include <sstream>
#include <map>
using namespace std;

void printFreq(string str[], int n) {
   map<string, int> freq;
   for(int i = 0; i < n; i++) {
       stringstream ss(str[i]);
       string word;
       while(ss >> word) {
           freq[word]++;
       }
   }
   for(auto it = freq.begin(); it != freq.end(); it++) {
       cout << it -> first << " : " << it -> second << endl;
   }
}

int main() {
    /*
        A stringstream associates a string object with a stream allowing
        you to read from the string as if it were a stream like cin.

        This class is extremely useful in parsing input.
        Count the number of words in a string
    */
    string str[] = {"hello world", "hello hello hello", "string stream awesome", "hello"};
    int n = sizeof(str) / sizeof(str[0]);
    printFreq(str, n);
    return 0;
}