/*
    return the count of number of trailing zeroes in n!

    number of times factors of 10's are occuring.
    occur(2) > occur(5).

    so num(zeroes) = occur(5) in n!

    num(zeroes) in 10! = floor(10/5) + floor(10/25)
                       = 2 + 0 = 2
    num(zeroes) in 100! = floor(100/5) + floor(100/ 25) + floor(100 / 125)
                        = 20 + 4 + 0 = 24
    
    100! = 1.2.3.4.5...10..25...50...75...100

    num(5) = 100 / 5 = 20 {5, 10, 15, 20, 25, ... 100}
    but 25 = 5.5.1 ; 50 = 5.5.2 ; 75 = 5.5.3 ; 100 = 5.5.4
    here 5 is occuring more than once.
    since 5 was already included once per number.
    100/25 = 4 gives the count of remaining 5's in each square of 5.
 
*/

#include <iostream>
#include <cmath>
using namespace std;

int trailZeroes(int N) {
    int i = 1, ans = 0;
    while(floor(N / pow(5, i)) != 0) {
        ans += floor(N / pow(5, i));
        i++;
    }
    return ans;
}

int main() {

    long long int N;
    cin >> N;

    cout << trailZeroes(N) << endl;
    

    return 0;
}