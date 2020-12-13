#include <iostream>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;

int main() {

    map<char, int> M;
    unordered_map<char, int> U;

    string s = "hello";
    for(char c : s) M[c]++; // O(nlogn) --> takes O(logn) time for every add and delete operation
    for(char c : s) U[c]++; // O(n) --> gets and sets the value in O(1) as no order is maintained.

    /* 
    if the order is not required then always go for unordered_map as it is much faster.
    insert(key, value) takes logn time in maps and constant time in unordered map
    erase(key) takes logn time in maps and constant time in unordered map.

    map uses BST hence the order is maintained and takes extra time.
    unordered map uses hashing and hence works in constant time.
    */

     
     

    return 0;
}

