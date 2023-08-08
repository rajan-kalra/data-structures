#include <iostream>
#include <vector>
using namespace std;

class DisjointSet {
    private: 
        vector<int> rank;
        vector<int> parent;
    public:
        DisjointSet(int n) {
            // init rank of each node as 0 in the beginning
            rank.resize(n + 1, 0);

            // init parent of each node as node itself
            parent.resize(n + 1);
            for (int i = 0; i <= n; i++) {
                parent[i] = i;
            }
        }

        int findUltimateParent(int node) {
            /**
             * if reached self node i.e if parent of node
             * is node itself, return the node
             */
            if (node == parent[node])
                return node;

             
            /**
             * while unwinding the recursion stack, set the
             * parent of node as node returned from the
             * recursive call
             */
            return parent[node] = findUltimateParent(parent[node]);
        }

        void unionByRank(int u, int v) {
            int ulp_u = findUltimateParent(u);
            int ulp_v = findUltimateParent(v);

            /**
             * if ultimate parent of u & v are same we
             * need not to do anything
             */
            if (ulp_u == ulp_v)
                return;

            /**
             * attach the node with lower rank to the
             * node with higher rank
             */
            if (rank[ulp_u] < rank[ulp_v]) {
                parent[ulp_u] = ulp_v;
            } else if (rank[ulp_v] < rank[ulp_u]) {
                parent[ulp_v] = ulp_u;
            /**
             * if the rank of u & v are same, then attach
             * either one to the other. Here we set parent
             * of v as parent of u
             */
            } else {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // if 3 and 7 same or not
    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }

    ds.unionByRank(3, 7);

    if (ds.findUltimateParent(3) == ds.findUltimateParent(7)) {
        cout << "Same\n";
    } else {
        cout << "Not same\n";
    }
    
    return 0;
}