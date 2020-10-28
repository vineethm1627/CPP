#include <iostream>
#include <cmath>
using namespace std;

int main() {

	int n;
	cin >> n;
	int num;
	while(n-- > 0) {
		cin >> num;
		int ans = 0, digit, p = 2, ind = 0;
		while(num > 0) {
			digit = num % 10;
			ans += digit * pow(p, ind);
			ind++;
			num /= 10;
		}
		cout << ans << endl;
	}
	return 0;
}