/*
    Find the presence of the pattern in the given input string.
    Define a notation and according to that notation, convert a string to an integer.

    we find the hash of the pattern.
    for every substring of the input text string, we will find the hash of the substring.
    If this hashed value matches with the hash value of the pattern string, we can confirm the presence of the pattern string in the given input string.

        map each character to integer.
        a -- 1
        b -- 2
        ..
        z -- 26

        p = prime number = 31
        mod = 1e19 + 7 = 1000000007
        "abcd" = (a*p^0 + b*p^1 + c*p^2 + d*p^3) % mod

        This method is known as "Polynomial Rolling Hash Function" 

    Disadvantages:
        Hashing has collisions
        High probability to produce correct results (works in CP env and not production level)


*/
#include <iostream>
using namespace std;

#define ll long long int
 
ll poly_hash_string(string s) {
    ll p = 31, m = 1e9 + 7;
    ll p_power = 1, hash_value = 0;
    for(int i = 0; s[i]; i++) {
        hash_value += p_power*(s[i] - 'a' + 1);
        p_power *= p;
        p_power %= m;
        hash_value %= m;
    }
    return hash_value;
} 
 
int main() {
    
    string s = "abababab";
    cout << poly_hash_string(s) << '\n';
 
    return 0;
}