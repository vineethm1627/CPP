/*
    Various ways to swap 2 variables
        1. swap(x, y);
    
        2. In case of integers
           x = x + y;
           y = x - y;
           x = x - y;
        
        3. temp = x;
           x = y;
           y = temp;
        
        4. tie(x, y) = make_tuple(y, x);
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int w, x, y, z;
	// multiple assignment at the same time.
	tie(w, x, y, z) = make_tuple(10, 20, 30, 40);
	
	cout << w << " " << x << " " << y << " " << z <<endl;
	
    // swapping x and y values.
	tie(x, y) = make_tuple(y, x);
	
	cout << x << " " << y << endl;
	
	return 0;
}

