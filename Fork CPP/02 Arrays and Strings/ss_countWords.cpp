#include <iostream>
#include <sstream>
using namespace std;

int countWords(string str[], int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        stringstream ss(str[i]);
        string word;
        while(ss >> word) {
            count++;
        }
    }
    return count;
}

int main() {
    /*
        A stringstream associates a string object with a stream allowing
        you to read from the string as if it were a stream like cin.

        This class is extremely useful in parsing input.
        Count the number of words in a string
    */
   string str[] = {"hello world", "vineeth", "string stream awesome"};
   int n = sizeof(str) / sizeof(str[0]);
   cout << "Number of words are : " << countWords(str, n);

    return 0;
}