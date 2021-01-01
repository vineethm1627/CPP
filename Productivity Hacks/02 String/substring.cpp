/*
    str.substr(arg1, arg2);
    arg1 --> starting index of the substring
    arg2 --> length of the substring to be fetched
*/
#include <bits/stdc++.h>
using namespace std;


int main() {
	
    string str = "Geeks love GeeksforGeeks";
    vector<string> words;
    
    int len, start = 0, n = str.size();
    
    for(int i = 0 ; i < n ; i++){
        if(str[i] == ' '){
            len = i - start;
            words.push_back(str.substr(start, len));
            start = i + 1;
        }
    }
    
    // last word
    len = n - start;
    words.push_back(str.substr(start, len));
    // printing all the words in the string
    for(auto word : words){
        cout<< word << endl;
    }
	
	return 0;
}