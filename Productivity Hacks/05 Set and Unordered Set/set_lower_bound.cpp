#include <iostream>
#include <set>
using namespace std;

/*
    s.lower_bound(..) --> O(logn) for bidirectional iterators
    lower_bound(..,..,..) --> O(n) in this case, but O(logn) for random access iterators if sorted.

    In sets, both forward traversal and backward traversal exists but random access similar to vectors is not present.
    In simple words set elements cannot be indexed.
    To provide indexing capacity to sets, use PBDS.
    order_of_key(); value --> index
    find_by_order(); index --> value
*/
 
int main() {

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(1);
    s.insert(4);

    cout << "size of the set: " << s.size() << endl;
    cout << "lower_bound of 2: " << *lower_bound(s.begin(), s.end(), 2) << endl;
    cout << "set lower_bound of 2: " << *s.lower_bound(2) << endl;

    return 0;
}