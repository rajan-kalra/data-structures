#include <iostream>
#include <vector>
using namespace std;
 
// Adjacency List to represent weighted undirected graph
int main() {
  int n, e;
  cin >> n >> e;
 
  // declare an array of vector containing pairs
  vector<pair<int,int>> adj[n+1]; 
 
  // an edge needs to be represented b/w u-v & v-u since
  // an undirected graph. We also add corresponding weight
  // with each node to represent weighted undirected graph
  for(int i = 0; i < e; i++) {
    int u, v, wt;
    cin >> u >> v >> wt;
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }
  
  return 0;
}