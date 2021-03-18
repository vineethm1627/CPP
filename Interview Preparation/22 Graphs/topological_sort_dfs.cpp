/*
    Task dependencies.
    Topological sorting for a graph is not possible if the graph is not a DAG.
    It is a linear ordering of the vertices such that for every directed edge u, v,
    vertix u comes before v in the ordering.
    A DAG is a directed graph without any cycle.
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
        // directed edge
        void addEdge(T x, T y) {
            m[x].push_back(y);
        }

        // recursive function that will traverse the graph
        void DFS_helper(T source, map<T, bool> &visited, stack<T> &s) {
            visited[source] = true;
            // go to any neighbour of the node that is not visited
            for(T nbr : m[source]) {
                if(!visited[nbr]) {
                    DFS_helper(nbr, visited, s);
                }
            }
            // finally push the source, when all the neighbours are pushed
            s.push(source);
        }

        void DFS() {
            map<T, bool> visited;
            stack<T> s;
            // mark all the nodes as not visited
            for(auto const p : m) 
                visited[p.first] = false;
            
            // call the helper function
            for(auto const p : m) {
                if(!visited[p.first])
                    DFS_helper(p.first, visited, s);
            }
            
            // print the topological order
            while(!s.empty()) {
                cout << s.top() << " ";
                s.pop();
            }
        }
};

int main() {

    Graph<string> g;
    g.addEdge("Python", "DataPreprocessing");
    g.addEdge("Python", "PyTorch");
    g.addEdge("Python", "ML");
    g.addEdge("DataPreprocessing", "ML");
    g.addEdge("ML", "DL");
    g.addEdge("DL", "FaceRecognition");
    g.addEdge("DataSet", "FaceRecognition");

    g.DFS();

    return 0;
}