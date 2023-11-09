#include<iostream>
#include<vector>
using namespace std;

class Solution {
private:
    bool dfs(int node, int col, vector<int> &color, vector<int> adj[]) {
        color[node] = col; 
        
        // traverse adjacent nodes
        for(auto it : adj[node]) {
            // if uncoloured
            if(color[it] == -1) {
                if(dfs(it, !col, color, adj) == false) return false; 
            }
            // if previously coloured and have the same colour
            else if(color[it] == col) {
                return false; 
            }
        }
        
        return true; 
    }

public:
    bool isBipartite(int V, vector<int>adj[]) {
        // init array of colors
        vector<int> color(V, -1);
        
        // for connected components
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                // break the loop if graph is found to be non-bipartite
                if (dfs(i, 0, color, adj) == false) 
                    return false; 
            }
        }
        return true; 
    }
};

void addEdge(vector <int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

int main(){
    // V = 4, E = 4
    vector<int>adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    bool ans = obj.isBipartite(4, adj);    
    if(ans)cout << "1\n";
    else cout << "0\n";  

    return 0;
}