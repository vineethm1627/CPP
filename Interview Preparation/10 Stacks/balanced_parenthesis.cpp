#include <iostream>
#include <stack>
using namespace std;

bool balanced(string str) {
    stack<char> s;
    for(int i = 0; str[i]; i++) {
        char ch = str[i];
        if(ch == '(')
            s.push(ch);
        else if(ch == ')') {
            if(s.empty() or s.top() != '(')
                return false;
            s.pop();
        }
    }
    return s.empty();
}

int main() {

    string str;
    getline(cin, str);

    if(balanced(str))
        cout << "balanced" << endl;
    else
        cout << "not balanced" << endl;

    return 0;
}