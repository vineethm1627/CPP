// way to represent a weighted graph using a hashmap.

#include <iostream>
#include <map>
#include <list>
using namespace std;
 
class Graph {
    map<string, list<pair<string, int>>> m;
public:
    void addEdge(string x, string y, bool bidir, int weight) {
        m[x].push_back(make_pair(y, weight));
        if(bidir)
            m[y].push_back(make_pair(x, weight));
    }

    void printAdjList() {
        // iterate over all the vertices
        for(auto const p : m) {
            cout << "source " << p.first << " -> ";
            for(auto const x : p.second)
                cout << "(" << x.first << "," << x.second << ")" << " ";
            cout << endl;
        }
    }
}; 
 
int main() {
    
    Graph g;
    // true for bidirectional edge
    g.addEdge("A", "B", true, 20);
    g.addEdge("B", "D", true, 40);
    g.addEdge("A", "C", true, 10);
    g.addEdge("C", "D", true, 40);
    g.addEdge("A", "D", false, 50);

    g.printAdjList();
 
    return 0;
}