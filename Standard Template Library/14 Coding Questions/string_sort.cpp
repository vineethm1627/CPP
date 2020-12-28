/*
    Nishant is a very naughty boy in Launchpad Batch. One day he was playing with strings, and randomly shuffled them all. Your task is to help Nishant Sort all the strings ( lexicographically ) but if a string is present completely as a prefix in another string, then string with longer length should come first. Eg bat, batman are 2 strings and the string bat is present as a prefix in Batman - then sorted order should have - Batman, bat.

    Input Format
    N(integer) followed by N strings.

    Constraints
    N<=1000

    Output Format
    N lines each containing one string.

    Sample Input
    3
    bat
    apple
    batman

    Sample Output
    apple
    batman
    bat

    Explanation
    In mathematics, the lexicographic or lexicographical order (also known as lexical order, dictionary order, alphabetical order or lexicographic(al) product) is a generalization of the way words are alphabetically ordered based on the alphabetical order of their component letters.
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(string s1, string s2) {
	if(s1.find(s2) != string::npos)
		return true;
	return s1 < s2;
} 

int main() {

	int n;
	cin >> n;
	cin.get();
	vector<string> v(n);

	for(int i = 0; i < n; i++)
		getline(cin, v[i]);
	sort(v.begin(), v.end(), compare);
	for(string s : v) 
		cout << s << endl;

	return 0;
}