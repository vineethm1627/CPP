#include <bits/stdc++.h>
using namespace std;

int main()
{
	map<int, int> mp;
	mp.insert({ 1, 2 });
	mp.insert({ 3, 4 });
	mp.insert({ 5, 6 });

	for (auto p: mp) {
		cout << p.first << ' ' << p.second << '\n';
	}
	cout << "------------\n";

	unordered_map<int, int> ump1;

	for (auto p: mp) {
		ump1.insert({ p.first, p.second });
	}
	for (auto p: ump1) {
		cout << p.first << ' ' << p.second << '\n';
	}
	cout << "------------\n";

	unordered_map<int, int> ump2(mp.begin(), mp.end());
	for (auto p: ump2) {
		cout << p.first << ' ' << p.second << '\n';
	}

	return 0;
}