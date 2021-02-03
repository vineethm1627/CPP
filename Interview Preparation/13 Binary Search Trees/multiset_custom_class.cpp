#include <iostream>
#include <set>
using namespace std;

#define psi pair<string, int>

// custom compare function
class compare {
    public:
        bool operator()(psi p1, psi p2) {
            return p1.second > p2.second;
        }
};

int main() {
    
    psi p[4];
    p[0] = make_pair("B", 100);
    p[1] = make_pair("A", 40);
    p[2] = make_pair("C", 120);
    p[3] = make_pair("D", 10);

    // pair -> name, money

    multiset<psi> ms(p, p + 4); // orders on the basis of the first element ie. name

    for(auto i : ms) {
        cout << i.first << " " << i.second << endl;
    }
    cout << endl;
    multiset<psi, compare> s(p, p + 4); // orders on the basis of custom comparator passed
    for(auto i : s) {
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}