#include <iostream>
#include <cstring>
using namespace std;

void removeconsecutiveDuplicates(char a[]) {
    // idea is to skip the similar characters.
    int len = strlen(a);
    if(len <= 1) {
        return;
    }
    
    int prev = 0; // prev character.
    for(int cur = 1; cur < len; cur++) {
        if(a[cur] != a[prev]) {
            a[++prev] = a[cur];
        }
    }
     a[++prev] = '\0';
}

int main() {
    // remove consecutive duplicate characters from a string inplace.
    // ex : ccoooding --> coding
    char a[1000];
    cout << "Enter any string : ";
    cin.getline(a, 1000);

    removeconsecutiveDuplicates(a);
    cout << "Output string : ";
    cout << a << endl;

    return 0;
}