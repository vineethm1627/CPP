/*
    In this problem, the graph could contain multiple connected components.
    So we might need to run the BFS algorithm multiple times.
    Given an unidrected graph, check if it contains a cycle.
    A graph is not a tree if it contains a cycle.

    If we visit a node via more than one path then we have a cycle.
    For this purpose, we maintain a visited array.
    If the visited node is the parent of the given node, then it can be ignored.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool bfs(vector<int> adj[], int source, int V, vector<bool> &visited) {
        queue<int> q;
        q.push(source);
        visited[source] = true;
        vector<int> parent(V, -1);
        // apply BFS
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            
            // visit the neighbours of this node
            for(const int nbr : adj[front]) {
                if(!visited[nbr]) {
                    visited[nbr] = true;
                    parent[nbr] = front;
                    q.push(nbr);
                }
                else if(parent[front] != nbr) 
                    return true;
            }
        }
        return false;
    }
    
    // the graph could contain disconnected components
	bool isCycle(int V, vector<int>adj[]){
	    vector<bool> visited(V, false);
	    // go through each node and call BFS on every non-visited node
	    for(int i = 0; i < V; i++) {
	        // cycle is detected
	        if(!visited[i] and bfs(adj, i, V, visited))
	            return true;
	    }
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}