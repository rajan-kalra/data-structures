#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
    void dfs(int node, vector<int> &visited, stack<int> &st, vector<int> adj[]) {
        visited[node] = 1;
        for (auto it : adj[node]) {
            if (visited[it] == false)
                dfs(it, visited, st, adj);
        }

        // insert the node to stack once all recursion are completed
        st.push(node);
    }

public:
    // Function to return list containing vertices in Topological order.
    vector<int> topoSort(int V, vector<int> adj[]) {
        vector<int> visited(V, 0);
        stack<int> st;

        for (int i = 0; i < V; i++) {
            if (visited[i] == false) {
                dfs(i, visited, st, adj);
            }
        }

        vector<int> ans;
        while (st.empty() == false) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};


int main() {
    // V = 6;
    // node 0 & 1 has no adjacent nodes
    // node 2 has only 3 as adjacent node
    // node 3 has only 1 as adjacent node
    // node 4 has only 0 & 1 as adjacent node
    // node 5 has only 0 & 2 as adjacent node
    vector<int> adj[6] = {
                            {},
                            {},
                            {3},
                            {1},
                            {0, 1},
                            {0, 2}
                        };
    int V = 6;
    Solution obj;
    vector<int> ans = obj.topoSort(V, adj);

    for (auto node : ans) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}