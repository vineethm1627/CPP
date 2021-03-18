/*
    Given an unidrected graph, check if it is a tree or not.
    A graph is not a tree if it contains a cycle.

    If we visit a node via more than one path then we have a cycle.
    For this purpose, we maintain a visited array.
    If the visited node is the parent of the given node, then it can be ignored.
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
            l[y].push_back(x);
        }

        bool isTree() {
            vector<bool> visited(V, false);
            vector<int> parent(V);
            queue<int> q;
            // initially parent of a node is the node itself
            for(int i = 0; i < V; i++) 
                parent[i] = i;
            
            int source = 0;
            q.push(source);
            visited[source] = true;

            while(!q.empty()) {
                int front = q.front();
                q.pop();

                // visit the neighbours of this node
                for(int const nbr : l[front]) {
                    // cycle is detected
                    if(visited[nbr] and parent[front] != nbr)
                        return false;
                    else if(!visited[nbr]) {
                        visited[nbr] = true;
                        parent[nbr] = front;
                        q.push(nbr);
                    }
                }
            }
            return true;
        }
};

int main() {

    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(3, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);

    if(g.isTree())
        cout << "Is a tree" << endl;
    else    
        cout << "Not a tree" << endl;

    return 0;
}
