/*
    Take as input S, a string. Write a function that returns the character with maximum frequency. Print the value returned.

    Input Format
    String

    Constraints
    A string of length between 1 to 1000.

    Output Format
    Character

    Sample Input
    aaabacb
    Sample Output
    a
    Explanation
    For the given input string, a appear 4 times. Hence, it is the most frequent character.
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

	string s;
	getline(cin, s);

	unordered_map<char, int> m;
	for(char c : s)
		m[c]++;
	
	int freq = 0;
	char c;
	for(auto i : m) {
		if(i.second > freq) {
			freq = i.second;
			c = i.first;
		}
	}
	cout << c;
	return 0;
}