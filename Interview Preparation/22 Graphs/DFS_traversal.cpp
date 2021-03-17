// DFS uses stack while BFS uses queue

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
            cout << source << " ";
            visited[source] = true;
            // go to any neighbour of the node that is not visited
            for(T nbr : m[source]) {
                if(!visited[nbr]) {
                    DFS_helper(nbr, visited);
                }
            }
        }

        void DFS(T source) {
            map<T, bool> visited;
            // mark all the nodes as not visited
            for(auto const p : m) 
                visited[p.first] = false;
            
            DFS_helper(source, visited);
        }
};

int main() {

    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(3, 0);

    g.DFS(0);

    return 0;
}