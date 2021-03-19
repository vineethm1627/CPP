/*
   Cycle detection in directed graph using DFS.
   If a directed graph contains a back edge, then it contains a cycle.
   A back edge is an edge from a node to an ancestor of the node in the same path.
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

        void addEdge(int x, int y) {
            l[x].push_back(y);
        }

        bool cycle_helper(int node, bool *visited, bool *stack_path) {
            visited[node] = true;
            // add node to the stack path, indicates it is a part of the current path
            stack_path[node] = true;

            for(const int nbr : l[node]) {
                // back edge, cycle detected.
                if(stack_path[nbr])
                    return true;
                else if(!visited[nbr]) {
                    bool got_cycle = cycle_helper(nbr, visited, stack_path);
                    if(got_cycle)
                        return true;
                }
            }
            // when we leave the node, it is no longer a part of our current path
            stack_path[node] = false;
            return false;
        }

        bool contains_cycle() {
            bool *visited = new bool[V];
            bool *stack_path = new bool[V];
            
            fill(visited, visited + V, false);
            fill(stack_path, stack_path + V, false);

            return cycle_helper(0, visited, stack_path);
        }
};

int main() {

    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(1, 5);
    g.addEdge(5, 6);
    g.addEdge(4, 2); // back edge
    
    if(g.contains_cycle())
        cout << "contains cycle";
    else
        cout << "doesn't contain cycle";

    return 0;
}
