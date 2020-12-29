/*
    Given a string containing duplicates, print all its distinct permutations such that there are no duplicate permutations and all permutations are printed in a lexicographic order.

    Input Format
    The first and only line of the test case contains the input string.

    Constraints
    Length of the string <= 8

    Output Format
    Print all the distinct permutations in a lexicographic order such that each permutation is in a new line. Note that there should not be any duplicate permutations.

    Sample Input
    ABA

    Sample Output
    AAB
    ABA
    BAA

    Explanation
    The possible permutations for the given string are { "AAB" , "AAB" , "ABA" , "BAA" } . We skip the repeating "AAB" permutation and only print it in once. Also we print the final output in lexicographical order.

*/
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	string s;
	getline(cin, s);

	sort(s.begin(), s.end());
	do {
		cout << s << endl;
	}while(next_permutation(s.begin(), s.end()));

	return 0;
}