// implementation of stack as a vector.

#include <iostream>
#include <vector>
using namespace std;

struct Stack {
    vector<int> v;

    void push(int x) {
        v.push_back(x);
    }

    int pop() {
        int res = v.back();
        v.pop_back();
        return res;
    }

    int size() {
        return v.size();
    }

    bool isEmpty() {
        return v.empty();
    }

    int peek() {
        return v.back();
    }
};

int main() {

    Stack s;
    for(int i = 1; i < 5; i++) {
        s.push(i);
    }
    cout << "Size : " << s.size() << endl;
    cout << "Pop : " << s.pop() << endl;
    cout << "Size : " << s.size() << endl;
    cout << "Peek : " << s.peek() << endl;
    cout << "Empty : " << s.isEmpty() << endl;

    return 0;
}