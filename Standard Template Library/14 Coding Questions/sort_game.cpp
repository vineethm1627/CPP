/*
    Sanju needs your help! He gets a list of employees with their salary. The maximum salary is 100.

    Sanju is supposed to arrange the list in such a manner that the list is sorted in decreasing order of salary. And if two employees have the same salary, they should be arranged in lexicographical manner such that the list contains only names of those employees having salary greater than or equal to a given number x.

    Help Sanju prepare the same!

    Input Format
    On the first line of the standard input, there is an integer x. The next line contans integer N, denoting the number of employees. N lines follow, which contain a string and an integer, denoting the name of the employee and his salary.

    Constraints
    1 <= N <= 10^5 1 <= | Length of the name | <= 100 1 <= x, salary <= 100

    Output Format
    You must print the required list.

    Sample Input
    79
    4
    Eve 78
    Bob 99
    Suzy 86
    Alice 86

    Sample Output
    Bob 99
    Alice 86
    Suzy 86
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define psi pair<string, int>

bool compare(psi p1, psi p2) {
	if(p1.second > p2.second)
		return true;
	else if(p1.second == p2.second)
		return p1 < p2;
	else
		return false;
}

int main() {

	int key, n;
	cin >> key >> n;

	vector<psi> p;

	for(int i = 0; i < n; i++) {
		string name;
		int salary;
		cin >> name >> salary;
		if(salary >= key) 
			p.push_back(make_pair(name, salary));
	}

	sort(p.begin(), p.end(), compare);
	for(auto it : p) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}