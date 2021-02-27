#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) c.begin(), c.end()
#define tr(c, i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c, x) (c.find(x) != c.end())
#define cpresent(c, x) (find(all,(c),x) != c.end())

int main() {
    
    // creating vector from map
    map<string, int > M;
    vector<pair<string, int >> V(all(M));
    // this feature may be useful if you are not planning to change elements in the map
    // but want to use indices of the elements in a way that is impossible in a map.

    // copying data between containers
    // This algorithm copies elements from the first interval to the second one
    vector<int> v1;
    vector<int> v2;

    // copy v2 to the end of v1
    v1.resize(v1.size() + v2.size());
    copy(all(v2)), v1.size() - v2.size());

    // performing set operations
    int data1[] = {1, 2, 5, 6, 8, 9, 10};
    int data2[] = {0, 2, 3, 4, 7, 8, 10};
    int n1 = sizeof(data1) / sizeof(data1[0]);
    int n2 = sizeof(data2) / sizeof(data2[0]);
    vector<int> v1(data1, data1 + n1);
    vector<int> v2(data2, data2 + n2);
    vector<int> temp(max(n1, n2));

    vector<int> result = vector<int>(temp.begin(), set_intersection(all(v1), all(v2), temp.begin()));
    // if you just want the count of elements in common
    int count = set_intersection(all(v1), all(v2), temp.begin()) - temp.begin();

    // find the sum of elements in a vector
    vector<int> v = {1, 2, 3, 4, 5};
    int sum = accumulate(all(v), 0);
    long long sum = accumulate(all(v), (long long)0);

    // find the product of elements in a vector
    int product = accumulate(all(v), double(1), multiplies<double>());

    return 0;
}
