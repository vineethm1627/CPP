// Breadth First Search 

#include <iostream>
#include <map>
#include <list>
#include <queue>
using namespace std;

template <class T>
class Graph {
        map<T, list<T>> m;
    public:
        // assuming edges are bidirectional
        void addEdge(int x, int y) {
            m[x].push_back(y);
            m[y].push_back(x);
        }

        void BFS(T source) {
            map<T, bool> visited;
            queue<T> q;
            q.push(source);
            visited[source] = true;

            while(!q.empty()) {
                T front = q.front();
                q.pop();
                cout << front << " ";
                // find neighbours of this node
                for(const T nbr : m[front]) {
                    if(!visited[nbr]) {
                        // push the neighbour in the queue
                        q.push(nbr);
                        // mark the neighbour as visited
                        visited[nbr] = true;
                    }    
                }
            }
        }

        void printAdjList() {
            // iterate through all the vertices
            for(auto const p : m) {
                cout << "source: " << p.first << " -> ";
                for(auto const x : p.second) 
                    cout << x << " ";
                cout << endl;
            }
        }
};

int main() {
    Graph<int> g;
    g.addEdge(0, 1);
    g.addEdge(0, 3);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3,4);
    g.addEdge(4,5);

    cout << "Adjacency list: \n";
    g.printAdjList();
    cout << "BFS traversal: ";
    g.BFS(0);

    return 0;
}

