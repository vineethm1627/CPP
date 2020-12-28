#include <iostream>
#include <set>
using namespace std;

// set container passed as a reference
void permute(char ch[], int i, set<string> &s) {
    if(ch[i] == '\0') {
        string temp(ch);
        s.insert(temp);
        return;
    }
    // recursive calls
    for(int j = i; ch[j] != '\0'; j++) {
        swap(ch[i], ch[j]);
        permute(ch, i + 1, s);
        swap(ch[i], ch[j]);
    }
}

int main() {

    char ch[100];
    cin >> ch; // aba i will get 6 permutations with repetitions
    set<string> s;
    permute(ch, 0, s);

    // print unique permutations in lexographic order.
    for(string per : s) {
        cout << per << endl;
    }

    return 0;
}