#include <iostream>
#include <vector>
using namespace std;
 
// Adjacency List to represent directed graph
int main() {
  int n, e;
  cin >> n >> e; 
 
  // declare an array of vectors
  // to represent adjacency list
  vector<int> adj[n+1]; 
 
  // an edge b/w u & v need to be represented
  // only b/w u-v & NOT v-u since this is directed graph
  for (int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
  }

  return 0;
}