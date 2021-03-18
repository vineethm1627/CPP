/*
    Given a graph, find out the number of connected components.
    A graph is said to be connected if you can reach all other nodes from a given node in the graph.
    Assume the graph is undirected.
*/
#include <iostream>
#include <map>
#include <stack>
#include <list>
using namespace std;

template <class T>
class Graph {
        map<T, list<T>> m;
    public:
        void addEdge(T x, T y) {
            m[x].push_back(y);
            m[y].push_back(x);
        }

        // recursive function that will traverse the graph
        void DFS_helper(T source, map<T, bool> &visited) {
            //cout << source << " ";
            visited[source] = true;
            // go to any neighbour of the node that is not visited
            for(T nbr : m[source]) {
                if(!visited[nbr]) {
                    DFS_helper(nbr, visited);
                }
            }
        }

        int DFS_connected() {
            map<T, bool> visited;
            // mark all the nodes as not visited
            for(auto const p : m) 
                visited[p.first] = false;
            int connected_components = 0;
            // iterate over all the vertices and initiate a dfs call if vertex is not visited
            for(auto const p : m) {
                if(!visited[p.first]) {
                    DFS_helper(p.first, visited);
                    connected_components++;
                }
            }
            return connected_components;
        }
};

int main() {

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(0, 3);
    g.addEdge(0, 4);

    g.addEdge(5, 6);
    g.addEdge(6, 7);

    g.addEdge(8, 8);

    cout << "no. of connected components: " << g.DFS_connected() << endl;

    return 0;
}