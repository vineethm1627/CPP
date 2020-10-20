#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool compare(string s1, string s2) {
    if(s1.length() == s2.length()) {
        return s1 < s2; // lewxographically.
    }
    return s1.size() < s2.size();
}

void bigSort(string str[], int n) {
    
    sort(str, str + n, compare);
    for(int i = 0; i < n; i++) {
        cout << str[i] << " ";
    }
    cout << endl;
}

int main() {

    string s[] = {"54443434343434", "724523015759812365464343432", 
                    "8701121012208333333333333345", "872434343", "1", "0", "100", "1000"};
    int n = sizeof(s) / sizeof(s[0]);
    cout << "Original string : " << endl;
    for(auto i : s) {
        cout << i << " ";
    }        
    cout << "\nSorted string : " << endl;
    bigSort(s, n);
    return 0;
}