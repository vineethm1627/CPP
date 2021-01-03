#include <bits/stdc++.h>
using namespace std;

void fun(int a[], int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

// vector passed by reference
void fun(vector<int> &v) {
	for (auto x: v) {
		cout << x << ' ';
	}
	cout << '\n';
}

int main() {

	int a[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(a) / sizeof(int);
	fun(a, n);

	vector<int> v = { 1, 2, 3, 4, 5 };
	fun(v);

	return 0;
}