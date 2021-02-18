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

    // generate prefix array
    ll prefix[text_size];
    for(int i = 0; i < text_size; i++) {
        prefix[i] = (text[i] - 'a' + 1) *power(p, i);
        prefix[i] %= m;
    }
    for(int i = 1; i < text_size; i++) {
        prefix[i] += prefix[i - 1];
        prefix[i] %= m;
    }
    
    for(int i = 0; i + pattern_size <= text_size; i++) {
        // substring s[0....r]
        // r = i + pattern_size - 1
        ll new_hash = prefix[i + pattern_size - 1];

        if(i - 1 >= 0)
            new_hash -= prefix[i - 1];
        // whenever we subtract from a mod value, add mod value and take mod again.
        new_hash = (new_hash + m) % m;

        if(new_hash == (pattern_hash * power(p, i)) % m)
            cout << i << '\n';
    }
}
 
int main() {
    string text = "abababbabab";
    string pattern = "aba";

    rabin_karp(text, pattern);
 
    return 0;
}