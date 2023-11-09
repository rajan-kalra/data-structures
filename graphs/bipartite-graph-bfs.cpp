#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    private: 
        bool checkIfBipartite(int startNode, int V, vector<int>adjList[], vector<int> &colorArr) {
            queue<int> q;
            q.push(startNode);

            // coloring the start node with 0 at first
            colorArr[startNode] = 0;

            while (q.empty() == false) {
                int node = q.front();
                q.pop(); 
                
                for (auto neighbor : adjList[node]) {
                    /**
                     * check if adjacent node is not yet
                     * colored, color it with opposite color 
                     */
                    if (colorArr[neighbor] == -1) {
                        /**
                         * setting color of the node different
                         * from its adjacent node color
                         */
                        colorArr[neighbor] = !colorArr[node]; 
                        q.push(neighbor); 
                    // is the adjacent guy having the same color 
                    // someone did color it on some other path 
                    } else if(colorArr[neighbor] == colorArr[node]) {
                        return false; 
                    }
                }
            }

            return true; 
        }

    public:
        bool isBipartite (int V, vector<int>adj[]) {
            vector<int> colorArr(V, -1);
            
            for (int node = 0; node < V; node++) {
                // if not coloured
                if (colorArr[node] == -1) {
                    if (checkIfBipartite(node, V, adj, colorArr) == false) {
                        return false; 
                    }
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
    vector<int> adj[4];

    addEdge(adj, 0, 2);
    addEdge(adj, 0, 3);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 1);

    Solution obj;
    bool ans = obj.isBipartite(4, adj);
    if (ans)
        cout << "Bipartite";
    else
        cout << "Non-bipartite";

    return 0;
}