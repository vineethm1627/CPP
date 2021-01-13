#include <bits/stdc++.h>
using namespace std;
int main()
{
	// Example illustrating the .count() function
	map<int, int> mp; // no duplicate of keys
	for (int i = 2; i <= 10; i++) {
		mp.insert(make_pair(i, i + 1));
		mp.insert(make_pair(i, 2 * i));
	}
	cout << mp.count(2) << ' ' << mp.count(11) << '\n';
    cout << mp[2] << endl; // 2 3

	multimap<int, int> mmp;
	for (int i = 2; i <= 10; i++) {
		mmp.insert(make_pair(i, i + 1));
		mmp.insert(make_pair(i, 2 *i));
	}
	cout << mmp.count(2) << ' ' << mmp.count(11) << '\n';

	return 0;
}