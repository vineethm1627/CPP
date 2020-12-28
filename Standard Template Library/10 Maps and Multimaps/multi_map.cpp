#include <iostream>
#include <map>
using namespace std;

/*
    In multimap it is possible to have duplicates of key values
    Here also the keys are ordered.
    m["apple"] = 20;
    m["apple"] = 50;

    The operations work in O(logn) time. [Self-balancing BST]
        insert
        find
        erase
    
    
*/

int main() {

    multimap<char, string> m;
    int n;
    cin >> n;
    cin.get();
    for(int i = 0; i < n; i++) {
        char ch;
        string s;
        ch = cin.get();
        getline(cin, s);
       
        m.insert(make_pair(ch, s));
    }
    
    // delete the first key->value pair
    auto it = m.begin();
    m.erase(it); 

    // the next >= key element
    auto lb = m.lower_bound('b');
    cout << "lower_bound of b " << endl;
    if(lb != m.end()) 
        cout << lb->first << " " << (*lb).second << endl;

    // the next > key element (strictly greater)
    auto ub = m.upper_bound('b');
    cout << "upper_bound of b " << endl;
    if(ub != m.end()) 
        cout << ub->first << " " << ub->second << endl;

    // count of key elements
    cout << "count of key 'b' : " << m.count('b') << endl;

    // searching for a value
    auto f = m.find('d');
    if(f->second == "dog") {
        m.erase(f);
    }

    // finding all the values for the key value 'c'
    auto eq = m.equal_range('c');
    cout << "c => ";
    for(auto it = eq.first; it != eq.second; it++)
        cout << it->second << " ";
    cout << endl;


    // print the multimap
    cout << "------------------------------" << endl;
    cout << m.size() << endl;
    for(auto p : m) {
        cout << p.first << " " << p.second << endl;
    }

    

    


    return 0;
}