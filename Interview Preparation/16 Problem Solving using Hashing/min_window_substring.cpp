/*
    Find the smallest window in a string containing all the characters of the other string.
    
    string-> "hellloeeo world"
    pattern-> "eelo"

    use sliding window and hashing.
    expand towards the right to get the window, once you get the window you contract from the left to avoid
    useless characters.(either the char is not present in the pattern or its freq in the string is higher than what is required.)

*/
#include <iostream>
#include <climits>
using namespace std;
 

string findMinWindow(string s, string p) {
    int s_len = s.size();
    int p_len = p.size();

    int start = 0; // left pointer for shrinking the window
    int count = 0;
    int min_len = INT_MAX;
    int index = -1;

    if(p_len > s_len) 
        return "NONE";
    
    int freq_s[256] = {0};
    int freq_p[256] = {0};

    for(int i = 0; i < p_len; i++) {
        char ch = p[i];
        freq_p[ch]++;
    }
    
    // sliding window (expansion and contraction)
    for(int i = 0; i < s_len; i++) {
        char ch = s[i];
        freq_s[ch]++;

    
        if(freq_p[ch] != 0 and freq_s[ch] <= freq_p[ch])
            count++;
        
        // if all the characters match.
        if(count == p_len) {
            // start shrinking the window from left
            // remove unwanted characters
            char temp = s[start];
            while(freq_p[temp] == 0 or freq_s[temp] > freq_p[temp]) {
                freq_s[temp]--;
                start++;
                temp = s[start];
            }
            // window size
            int window_len = i - start + 1;
            if(window_len < min_len) {
                min_len = window_len;
                index = start;
            }
         }
    }
    if(index == -1)  
        return "None";
    
    string ans = s.substr(index, min_len); // {starting index, length}
    return ans;
}


int main() {
    
    string s = "hllloeaeo world";
    string p = "eelo";

    cout << findMinWindow(s, p) << endl;
 
    return 0;
}