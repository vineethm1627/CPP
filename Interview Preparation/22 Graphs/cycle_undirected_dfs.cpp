/*
   Cycle detection in undirected graph using DFS.
*/
#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;

class Graph {
    list<int> *l;
    int V;

    public:
        Graph(int V) {
            this->V = V;
            l = new list<int>[V];
        }

        void addEdge(int x, int y, bool directed = true) {
            l[x].push_back(y);
            if(!directed)
                l[y].push_back(x);
        }

        bool cycle_helper(int node, bool *visited, int parent) {
            visited[node] = true;

            for(const int nbr : l[node]) {
                if(!visited[nbr]) {
                    // make recursive call
                    bool got_cycle = cycle_helper(nbr, visited, node);
                    if(got_cycle)
                        return true;
                }
                // we found another path to reach the neighbour
                // cycle detected
                else if(nbr != parent)
                    return true;
            }
            return false;
        }

        bool contains_cycle() {
            bool *visited = new bool[V];
            fill(visited, visited + V, false);

            // assuming there are various DFS trees ie. disconnected components
            // so we initiate a DFS for every non-visited node until all the nodes are visited.
            for(int i = 0; i < V; i++) {
                if(!visited[i] and cycle_helper(i, visited, -1)) 
                    return true;
            }
            return false;
        }
        
};

int main() {

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 0);
    
    if(g.contains_cycle())
        cout << "contains cycle";
    else
        cout << "doesn't contain cycle";

    return 0;
}
