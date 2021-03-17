// way to represent a graph using array of lists of size v(number of vertices).

#include <iostream>
#include <list>
using namespace std;
 
class Graph {
    int v;
    // array of list
    list<int> *arr;
public:
    Graph(int v) {
        this->v = v;
        arr = new list<int>[v];
    }
    // bidirectional edge from node x to node y.
    void addEdge(int x, int y) {
        arr[x].push_back(y);
        arr[y].push_back(x);
    }

    void printAdjList() {
        // iterate over all the vertices
        for(int i = 0; i < v; i++) {
            cout << "vertex " << i << "-> ";
            for(const int nbr : arr[i])
                cout << nbr << " ";
            cout << endl;
        }
    } 
}; 
 
int main() {
    
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(2, 3);
    g.addEdge(1, 2);

    g.printAdjList();
 
    return 0;
}