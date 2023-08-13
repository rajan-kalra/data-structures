#include <iostream>
#include <queue>
using namespace std;
 
class Solution {
    public:
        bool checkForCycle(int sourceNode, int V, vector<int> adjList[], vector<bool> &visited) {
            /**
             * Create a queue for BFS
             * This queue has node & its parent
             */
            queue<pair<int, int>> q;

            visited[sourceNode] = true;

            // first node has parent as -1
            q.push({sourceNode, -1});

            while (q.empty() == false) {
                int node = q.front().first;
                int parent = q.front().second;
                q.pop();

                for (auto neighborNode : adjList[node]) {
                    if (visited[neighborNode] == false) {
                        visited[neighborNode] = true;
                        q.push({neighborNode, node});
                    // A node can be already visited but if a node
                    // is already visited & its parent is not 
                    } else if (parent != neighborNode) {
                        return true;
                    }
                }
            }

            return false;
        }

        bool isCyclePresent(int V, vector<int> adjList[]) {
            vector<bool> visited(V - 1, false);

            /**
             * Iterate through all the nodes to ensure there 
             * is no cycle present in any component if multiple
             * components are present
             */
            for (int i = 1; i <= V; i++) {
                if (visited[i] == 0) {
                    if (checkForCycle(i, V, adjList, visited))
                        return true;
                }
            }

            return false;
        }
};
 
void addEdge(vector<int> adj[],int u,int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}
 
int main() {
    vector<int> adj[5];

    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);

    Solution obj;
    int num = obj.isCyclePresent(5, adj);
    if (num == 1)
        cout << "Cycle detected using BFS!" << endl;
    else
        cout << "Cycle not detected using BFS!" << endl;

    return 0;
}