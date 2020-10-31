/*
    Given two strings S1 and S2 consisting of only lowercase characters whose anagrams are almost equal. 
    The task is to count the number of characters which needs to be edited(delete) to make S1 equal to S2.

    Input:
    1
    madame
    madam

    Output:
    1

    Explanation:
    Testcase 1: String S1 = madame, string S2 = madam. 
    character 'e' in first string needs to be deleted to make S1 equal to S2.

*/

#include <bits/stdc++.h>
using namespace std;

// Function Prototype
int countChars(string, string);

int main() {
	
	int testcase;
	
	cin >> testcase;
	
	while(testcase--){
	    string s1, s2;
	    cin >> s1 >> s2;   
	    cout << countChars(s1, s2) << endl;
	}
	
	return 0;
}
int countChars(string s1, string s2){
    map<int, int> m1, m2;
    for(int i = 0; i < s1.length(); i++) {
        m1[s1[i] - 'a']++;
    }
    for(int i = 0; i < s2.length(); i++) {
        m2[s2[i] - 'a']++;
    }
    int ans = 0;
    for(int i = 0; i < 26; i++) {
        ans += abs(m1[i] - m2[i]);
    }
    return ans;
}