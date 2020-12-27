#include <iostream>
#include <queue>
using namespace std;

// functors are also called as function objects.
class fun {
    public:
        // operator overloading ()
          void operator()() {
            cout << "Inside operator() function" << endl;
        }

        void operator()(string s) {
            cout << s << " ";
        }
      
};

int main() {

    fun f; // f is an object and here we are making a constructor call.
    f(); // call to the overloaded () operator
    // though f is an object, the above statement looks like a function call.
    f("c++");
    // since the object behaves like a function call, it is therefore called a functor.
    
    return 0;
}