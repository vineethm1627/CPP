#include <iostream>
#include <map>
using namespace std;

/*
     A map is an associative containers that provides a mapping between the key->value pairs.

     In C++ STL we have 2 container --> map and unordered_map

    Operations:
        insert
        find
        erase
    
    A map maintains a self-balancing BST(Binary Search Tree) and the key elements are ordered in nature.
    It takes O(logn) to retrieve a key->value pair.
    In map the keys are unique, stored only once. 
    Repetition of key values is not allowed in maps.

    unordered_map uses hashing to store the key->value pairs.
    It takes O(1) to retrieve a key->value pair.
*/

int main() {

    map<string, int> m;

    // insert
    m.insert({"Mango", 100});
    m.insert(make_pair("Apple", 80));
    
    pair<string, int> p;
    p.first = "Orange";
    p.second = 50;
    m.insert(p);

    m["Banana"] = 20;

    // search
    string fruit;
    getline(cin, fruit);

    // map<string, int>::iterator;
    auto it = m.find(fruit);
    if(it != m.end()) {
        cout << it->first << " " << it->second << " " << m[fruit] << endl;
    }
    else 
        cout << "fruit not found" << endl;

    // another way to find element by count
    // unique keys are stored only once
    // count(key) returns a value 0 or 1 indicating the absence/presence of the key element

    if(m.count(fruit)) 
        cout << "Present " << m.count(fruit) << endl;
    else 
        cout << "Absent " << m.count(fruit) << endl;
    
    cout << "-------------------------------" << endl;

    // printing all the key-value pairs
    for(pair<string, int> p : m) {
        cout << p.first << " " << p.second << endl;
    }
    cout << "-------------------------------" << endl;

    // erase a key->value pair.
    m.erase(fruit);
    cout << m.size() << endl;

    // update the price value
    m["Banana"] = 200;

    for(auto it = m.begin(); it != m.end(); it++) 
        cout << it->first << " : " << (*it).second << endl;
    cout << "-------------------------------" << endl;





    return 0;
}