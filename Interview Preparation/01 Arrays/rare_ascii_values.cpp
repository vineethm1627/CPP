/*
    Mohan is a geek who likes to find out different kind of combinations in numbers. Once, he discovered a rare category of numbers in which sum of digits of number is equal to sum of prime factors of number in such a way that if there is prime factor which itself has more than one digit then in that case, sum of digits of that particular prime factor and then it’s sum total with the other prime factors will be equal to sum of digits of the main number. Now Mohan has been given some test cases in which he has to recognize whether the given number in the test case is a rare number or not and then accordingly print the ASCII form of each digit of that rare number.

    Note: Don't include 1 as prime factor

    Input Format

    The input line contains only one integer "N" which has to be checked and accordingly print the output.

    Constraints

    1 ≤ N ≤ 1,00,00,000

    Output Format

    Check if N is a rare number then print the ASCII value of each digit else print "No".

    Sample Input 0

    6036
    Sample Output 0

    54485154
    Explanation 0

    6,036 = 2×2×3×503; 6,036 has a digit sum of 15, and the sum of the digits of its prime factors is also 15 i.e (2+2+3+5+0+3=15) If the sum of digits of input number is equal to sum of digit of its prime factor then it is a rare number Now you have to print ASCII value of each digit of this rare number Note: ASCII value if of character and not int i.e there is ASCII value for “6” but no ASCII for 6 6036 is a rare number; ASCII value for: 6 – 54 0 – 48 3 – 51 6 – 54

    Output: 54485154
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define lli long long int

vector<lli> primeFactors(lli n) {
    vector<lli> factors;
    
    while(n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }
    for(int i = 3; i * i <= n; i += 2) {
        if(n % i == 0) {
            while(n % i == 0) {
                factors.push_back(i);
                n /= i;
            }
        }
    }
    if(n > 1)
        factors.push_back(n);
    return factors;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    lli n;
    cin >> n;
    
    lli temp = n;
    int digit_sum = 0;
    while(temp) {
        digit_sum += temp % 10;
        temp /= 10;
    }
    vector<lli> factors = primeFactors(n);
    int factor_sum = 0;
    for(const lli num : factors) {
        lli temp = num;
        while(temp) {
            factor_sum += temp % 10;
            temp /= 10;
        }
    }
    //cout << factor_sum << endl;
    if(factor_sum != digit_sum) 
        cout << "No" << endl;
    else {
        // cout the ascii value
        string result;
        string num = to_string(n);
        for(const char c : num) {
            result += to_string((int)c);
        }
        cout << result << endl;
    }
    
    return 0;
}