#include <iostream>
#include <list>
using namespace std;

int main() {

    // creating an adjacency list for graph data structure.
    // dynamic array
    list< pair<int, int> > *l;
    cout << "enter the number of vertices ";
    int n, e, x, y, wt;
    cin >> n;
    l = new list< pair<int, int> >[n];

    cout << "enter the number of edges ";
    cin >> e;

    for(int i = 0; i < e; i++) {
        cin >> x >> y >> wt;
        l[x].push_back(make_pair(y, wt));
    }

    // print the adjacency list
    for(int i = 0; i < n; i++) {
        // print every linked list
        for(auto xp : l[i]) {
            cout << "(" << xp.first << "," << xp.second << ") "; 
        }
        cout << endl;
    }
    return 0;
}