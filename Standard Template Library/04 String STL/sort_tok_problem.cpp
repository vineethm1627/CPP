/*
Given a list of 'n' strings S0,S1,S2,……,Sn-1, each consisting of digits and spaces, the number of spaces is the same for each entry, the goal is to implement a variation of a sort command. None of the strings contains consecutive spaces. Also,
no string starts with a space nor ends with it. Spaces are used to divide string into columns, which can be used as keys in comparisons.

The program has to support the required parameters:

key: integer denoting the column used as a key in comparisons. The left-most column is denoted by 1.

reversed: boolean variable indicating whether to reverse the result of comparisons.

comparison-type: either lexicographic or numeric. Lexicographic means that we use Lexicographical order where for example (122 < 13) . Numeric means that we compare the strings by their numerical values, so (13 < 122) . 
If the comparison type is 'numeric' and numeric values of keys of Si and Sj are equal for i < j , then Si is considered strictly smaller than Sj because it comes first.

Input Format
In the first line, there is a single integer 'n' denoting the number of strings to sort. In the i-th of the following n lines there is a string Si.
In the last line, there are 3 space-separated values, denoting the values of variables 'key','reversed' , comparison-type.

Sample Input
3
92 022
82 12
77 13
2 false numeric

Sample Output
82 12
77 13
92 022

Explanation
The key for ordering is 2, reversal is false and ordering is numeric. Therefore, the keys 022, 12 and 13 should be ordered as 12, 13 and 022. Therefore, the final output is 82 12, 77 13 and 92 022.
*/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <sstream>
using namespace std;
// extracting key tokens
string extractStringAtKey(string str, int key) {
	// strtok requires char * array.
	// so extract the underlying char array from the string objectS
	// return the token at key specified

	// stringstream ss(str);
	// string word, res;
	// while(ss >> word) {
	// 	if(--key == 0) {
	// 		res = word;
	// 		break;
	// 	}
	// }
	// return res;

	char *s = strtok((char *)str.c_str(), " ");
	while(key > 1) {
		s = strtok(NULL, " ");
		key--;
	}

	return (string)s;
}

bool numericCompare(pair<string, string> s1, pair<string, string> s2) {
	// convert key to int
	string k1, k2;
	k1 = s1.second;
	k2 = s2.second;
	return stoi(k1) < stoi(k2);
}

bool lexioCompare(pair<string, string> s1, pair<string, string> s2) {
	return s1.second < s2.second;
}

int main() {	
	int n;
	cin >> n;
	cin.get(); // if you omit this line, error would be generated.
	string a[n];
	for(int i = 0; i < n; i++) {
		getline(cin, a[i]);
	}
	
	int key;
	string reversal, ordering;
	cin >> key >> reversal >> ordering;

	pair<string, string> strPair[100]; // string : key
	for(int i = 0; i < n; i++) {
		
		strPair[i].first = a[i]; // string
		strPair[i].second =  extractStringAtKey(a[i], key); // key
		
	}

	// sorting.
	if(ordering == "numeric") {
		sort(strPair, strPair + n, numericCompare);
	}
	else {
		sort(strPair, strPair + n, lexioCompare);
	}

	// reversal
	if(reversal == "true") {
		reverse(strPair, strPair + n);
	}

	for(int i = 0; i < n; i++) {
		cout << strPair[i].first << endl;
	}
	
	return 0;
}