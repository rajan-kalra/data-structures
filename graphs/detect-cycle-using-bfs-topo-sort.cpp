#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V, 0);
        // populating indegree array using the fact
        // that each node in the adjacency list
        // corresponding to a node has an incoming
        // edge from the node
        for (int node = 0; node < V; node++) {
            for (auto neighbour : adj[node]) {
                indegree[neighbour]++;
            }
        }

        // to start with, pushing all nodes with
        // indegree as 0 to queue
        queue<int> q;
        for (int node = 0; node < V; node++) {
            if (indegree[node] == 0) {
                q.push(node);
            }
        }

        int count = 0;
        // o(v + e)
        while (q.empty() == false) {
            int node = q.front();
            q.pop();

            count++;
            // node is in your topo sort
            // so please remove it from the indegree

            for (auto neighbour : adj[node]) {
                indegree[neighbour]--;
                if (indegree[neighbour] == 0)
                    q.push(neighbour);
            }
        }

        if (count == V)
            return false;
        return true;
    }
};


int main() {
    //V = 6;
    vector<int> adj[6] = {
                            {},
                            {2},
                            {3},
                            {4, 5},
                            {2}, {}
                        };
    int V = 6;
    Solution obj;
    bool ans = obj.isCyclic(V, adj);
    if (ans) cout << "True";
    else cout << "Flase";
    cout << endl;
    return 0;
}