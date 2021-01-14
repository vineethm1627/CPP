/*
    Design a stack class that supports the following operation.

        push()
        pop()
        top()
        getMin()
        getMax()
*/
#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MinMaxStack {
    vector<T> stack;
    vector<T> min_stack;
    vector<T> max_stack;

    public:

        void push(T data) {
            T cur_min = data;
            T cur_max = data;

            if(min_stack.size() > 0) {
                cur_min = min(cur_min, min_stack[min_stack.size() - 1]);
                cur_max = max(cur_max, max_stack[max_stack.size() - 1]); 
            }
            stack.push_back(data);
            min_stack.push_back(cur_min);
            max_stack.push_back(cur_max);
        }

        T get_min() {
            return min_stack[min_stack.size() - 1];
        }

        T get_max() {
            return max_stack[max_stack.size() - 1];
        }
        
        T top() {
            return stack[stack.size() - 1];
        }

        bool empty() {
            return stack.size() == 0;
        }

        void pop() {
            stack.pop_back();
            min_stack.pop_back();
            max_stack.pop_back();
        } 
};


int main() {

    MinMaxStack<int> s;
    s.push(1);
    s.push(5);
    s.push(3);
    s.push(8);

    cout << "max: " << s.get_max() << endl;
    cout << "min: " << s.get_min() << endl;
    cout << "element popped: " << s.top() << endl;
    s.pop();
    cout << "max: " << s.get_max() << endl;
    cout << "min: " << s.get_min() << endl;
    cout << "element popped: " << s.top() << endl;
    s.pop();
    cout << "max: " << s.get_max() << endl;
    cout << "min: " << s.get_min() << endl; 
    cout << "element popped: " << s.top() << endl;
    s.pop();
    cout << "max: " << s.get_max() << endl;
    cout << "min: " << s.get_min() << endl; 
    cout << "stack empty: " << s.empty();

    return 0;
}