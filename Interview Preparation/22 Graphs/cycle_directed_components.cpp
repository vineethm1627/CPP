#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool cycle_helper(int node, bool *visited, bool *stack_path, vector<int> adj[]) {
        visited[node] = true;
        // add node to the stack path, indicates it is a part of the current path
        stack_path[node] = true;
        
        for(const int nbr : adj[node]) {
            // check for backedge, indicates the presence of a cycle.
            if(stack_path[nbr])
                return true;
            // create a recursive call if the node is not already visited
            else if(!visited[nbr]) {
                bool got_cycle = cycle_helper(nbr, visited, stack_path, adj);
                if(got_cycle)
                    return true;
            }
        }
        // when we leave the node, it is no longer a part of our current path 
        stack_path[node] = false;
        return false;
    }

	bool isCyclic(int V, vector<int> adj[]) {
	   	bool *visited = new bool[V];
	   	bool *stack_path = new bool[V];
	   	
	   	fill(visited, visited + V, false);
	   	fill(stack_path, stack_path + V, false);
	   	
	   	// call the recursive helper function to detect cycle in different DFS trees
	   	for(int i = 0; i < V; i++) {
	   	    if(cycle_helper(i, visited, stack_path, adj))
	   	        return true;
	   	}
	   	return false;
	}
};

int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}