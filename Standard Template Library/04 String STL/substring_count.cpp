/*
    Sahil is done with his internship and now it's time to attend Geeks Classes to enhance knowledge of Data Structures. However, to join this class, he has been given a task to complete. The task is to count the occurrences of "gfg" in the given string, and if he completes this task, he qualifies for Geeks Classes. But, Sahil is facing some problem in solving this task, so help him.

    Input :
    First line of input contains "T" testcases. Next "T" lines contains Strings with lowercase characters.

    Output :
    For each testcase, output the count the ccurrences of "gfg"(continuous) present in string.

    Constraints :
    1 <= T <= 10
    1<= length_of_string <= 100

    Example :
    Input :
    2
    geefgfgksforgfgeeks
    dsajslsdlsfgf
    Output :
    2
    -1

    Explanation :
    #Test Case 1: In the first testcase, "gfg" occurs two times in the String. First ccurrence starts at index 4 and next starts at 12.
    #Test Case 2: In second testcase, there is no occurences of "gfg" in given string. So, it returned -1.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int T;
	cin >> T;
	cin.get(); // to take the "\n" after the int.
	
	while(T--) {
	    string str;
	    getline(cin, str);
	    int ans = 0;
	    
	    for(int i = str.find("gfg"); i != string::npos; i = str.find("gfg", i + 1)) {
	        ans++;
	    }
	    if(ans > 0) {
	        cout << ans << endl;
	    }
	    else {
	        cout << -1 << endl;
	    }
	    
	}
	return 0;
}