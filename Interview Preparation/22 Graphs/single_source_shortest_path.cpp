/*
    Single Source Shortest Path

    Note:
        For unweighted graph, distance calculation by level order traversal is the shortest distance.
        The level of that node will be the shortest distance from the source node.
*/

#include <iostream>
#include <map>
#include <list>
#include <queue>
#include <climits>
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
            // node -> distance
            map<T, int> distance;

            queue<T> q;
            q.push(source);
            // all other nodes will have infinity as initial distance
            for(auto p : m) {
                T node = p.first;
                distance[node] = INT_MAX;
            }
            distance[source] = 0;

            while(!q.empty()) {
                T front = q.front();
                q.pop();
                //cout << front << " ";
                // find neighbours of this node
                for(const T nbr : m[front]) {
                    // visiting the node for the first time.
                    if(distance[nbr] == INT_MAX) {
                        // push the neighbour in the queue
                        q.push(nbr);
                        // mark the neighbour as visited
                        distance[nbr] = distance[front] + 1;
                    }    
                }
            }
            // print the distance to every node from the source node
            cout << "Source node: " << source << endl;
            cout << "Destination : shortest distance\n";
            for(auto const p : m) {
                T node = p.first;
                int d = distance[node];
                cout << node << " : " << d << endl;
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
    g.BFS(0);

    return 0;
}

