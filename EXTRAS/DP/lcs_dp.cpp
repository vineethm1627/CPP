/*
Given two strings S1 and S2 with lengths M and N respectively, find the length of the longest common subsequence.
A subsequence of a string S whose length is K, is a string containing characters in same relative order as they are present in S, but not necessarily contiguous. Subsequences contain all the strings of length varying from 0 to K. For example, subsequences of string "abc" are -- ""(empty string), a, b, c, ab, bc, ac, abc.
Input Format :
First line will contain T(number of test case), each test case will consist of two lines.
Line 1: String S1
Line 2: String s2
Output Format :
Length of the longest common subsequence for each test case in a newline.
Constraints :
1 <= T <= 100
1 <= M <= 100
1 <= N <= 100

Time Limit: 1 sec
Sample Input 1:
1
adebc
dcadb
Sample Output 1:
3
Explanation of Sample Input 1:
"a", "d", "b", "c", "ad", "ab", "db", "dc" and "adb" are present as a subsequence in both the strings in which "adb" has the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
Sample Input 2:
1
abcd
acbdef
Sample Output 2:
3
Explanation of Sample Input 2:
"a", "b", "c", "d", "ab", "ac", "ad", "bd", "cd", "abd" and "acd" are present as a subsequence in both the strings S1 and S2 in which "abd" and "acd" are of the maximum length. There are no other common subsequence of length greater than 3 and hence the answer.
*/
#include<bits/stdc++.h>
using namespace std;

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lcs(string S1, string S2, int m, int n) {
    int L[m + 1][n + 1];
    int i, j;
    for(i = 0; i <= m; i++) {
        for(j = 0; j <= n; j++) {
            if(i == 0 or j == 0) {
                L[i][j] = 0;
            }
            else if(S1[i - 1] == S2[j - 1]) {
                L[i][j] = L[i - 1][j - 1] + 1;
            }
            else {
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
            }
        }
    }
    return L[m][n];
}

int main(){
    
    int T;
    cin >> T;
    cin.get(); // most important statement else the first string read will be "\n".
    
    while(T--) {
        string S1, S2;
        getline(cin, S1);
        getline(cin, S2);
        
        cout << lcs(S1, S2, S1.length(), S2.length()) << endl;
    }
    
    return 0;
}