#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class DisjointSet {

    public:
        vector<int> parent;
        vector<int> size;

        DisjointSet(int n) {
            parent.resize(n + 1);
            size.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) {
            if (node == parent[node])
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionBySize(int u, int v) {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if (ulp_u == ulp_v) return;
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);

        // creating disjoint set using adjacency matrix
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adj[i][j] == 1) {
                    // i and j
                    ds.unionBySize(i, j);
                }
            }
        }

        int count = 0;
        for (int i = 0; i < V; i++) {
            if (ds.parent[i] == i)
                count++;
        }

        return count;
    }
};

int main() {
    int V = 3;
    vector<vector<int>> adj = {{1, 0, 1}, {0, 1, 0}, {1, 0, 1}};

    Solution obj;
    int ans = obj.numProvinces(adj, V);
    cout << "The number of provinces is: " << ans << endl;
    return 0;
}