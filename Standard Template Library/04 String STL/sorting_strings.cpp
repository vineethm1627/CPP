#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

bool compare(string s1, string s2) {
    return s1.length() < s2.length(); // sorting in ascending order of length
}

int main() {
    int n;
    cout << "Enter the number of strings : ";
    cin >> n;
    cin.get(); // fetch any extra space after the number
    string s[n];
    for(int i = 0; i < n; i++) {
        getline(cin, s[i]);
    }
    cout << "---------------------" << endl;
    sort(s, s + n); //lexographic sorting
    cout << "sorting lexographically : ";
    for(string i : s) {
        cout << i << " ; ";
    }
    cout << "\nsorting based on length : ";
    sort(s, s + n, compare);
    for(string i : s) {
        cout << i << " ; ";
    }

    return 0;
}