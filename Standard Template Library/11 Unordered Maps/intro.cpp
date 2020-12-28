/*
    Implementation of HashTable.
    Separate chaining technique.

    Here the keys are not in sorted order.
    Insertion, deletion and find operations work in O(1) time on average.
    Exceptions occur on repetitive collisions and rehashing

*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {

    unordered_map<string, int> m;

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