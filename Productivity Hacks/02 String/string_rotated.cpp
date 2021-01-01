/*
    check if string B is a rotation of string A or not
*/
#include <bits/stdc++.h>
using namespace std;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main() {
	
    fastIO();
    string A = "ABCD";
    string B = "DABC";
    
    if(A.length() != B.length()){
        cout<< "No" << endl;
        return 0;
    }
    
    string temp = A + A;
    
    if(temp.find(B) != string::npos){
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    
    
	
	return 0;
}