/*
Online judge input and output
given n numbers print their squares.
    input file :
        3
        1
        2
        3
    output file :
        1
        4
        25

    Note : to provide input from a file, in the terminal 
           ./onlineJudgee < input_file.txt > output_file.txt

            you just need to provide the input file, the output file gets created on its own.
*/  
#include <iostream>
using namespace std;

int main() {

    int n;
    cin >> n;
    int num;
    while(n-- > 0) {
        cin >> num; // comes from an input file
        cout << num * num << endl; // goes to the output file
        // on the console, both will be printed one after the other.
    }
    return 0;
}
