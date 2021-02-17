/*
    String pattern matching.
    Algorithm:
        1. Hash the pattern using polynomial rolling hashing function.
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
        2. Performing rolling operation instead of calculating the hash for every window
            Remove first character value from the hash value. [character going out of the current window]
            in the remaining hash divide by p.
            include the latest character in the sliding window.
        

        Fermat's Little Theorem:
            p = prime
            a^(p-1) % p = 1 % p
            a^-1 = inverse of a = a(p-2) % p
*/
#include <iostream>
using namespace std;
 
#define ll long long int

const ll m = 1e9 + 7;
const ll p = 31;

// binary exponentiation
ll power(ll a, ll b) {
    ll ans = 1;
    while(b) {
        int last_bit = (b & 1);
        if(last_bit) {
            ans *= a;
            ans %= m;
        }
        a *= a;
        b >>= 1;
        a %= m;
    }
    return ans;
}

ll inverse(ll a) {
    // a^-1 % p = a^(0-2)%p
    return power(a, m - 2);
}

ll poly_hash_string(string s) {
    ll p_power = 1, hash_value = 0;
    for(int i = 0; s[i]; i++) {
        hash_value += p_power*(s[i] - 'a' + 1);
        p_power *= p;
        p_power %= m;
        hash_value %= m;
    }
    return hash_value;
}  

// prints the indices of the occurrence of the pattern string
void rabin_karp(string text, string pattern) {
    ll pattern_hash = poly_hash_string(pattern);
    int text_size = text.size(), pattern_size = pattern.size();
    // hash for the first window
    ll text_hash = poly_hash_string(text.substr(0, pattern_size));
    if(text_hash == pattern_hash)
        cout << 0 << '\n';
    // process the remaining window
    for(int i = 1; i + pattern_size <= text_size; i++) {
        ll new_hash = text_hash;
        // remove the (i-1)th character going out of the window
        new_hash = (new_hash - (text[i - 1] - 'a' + 1) + m) % m;
        // reduce the powers by 1
        new_hash *= inverse(p);
        new_hash %= m;
        // add the current element into the window
        new_hash += (text[i + pattern_size - 1] - 'a' + 1) * power(p, pattern_size - 1);
        new_hash %= m;

        if(new_hash == pattern_hash)
            cout << i << '\n';
        text_hash = new_hash;
    }
}
 
int main() {
    string text = "ababab";
    string pattern = "aba";

    rabin_karp(text, pattern);
 
    return 0;
}