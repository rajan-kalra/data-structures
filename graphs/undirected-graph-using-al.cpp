#include <iostream>
#include <vector>
using namespace std;
 
// Adjacency List to represent undirected graph
int main() {
  int n, e;
  cin >> n >> e; 
 
  // declaring an array of vectors
  vector<int> adj[n+1]; 
 
  // each edge needs to represented for both directions i.e
  // v as adjacent node to u & u as adjacent node to v as its
  // an undirected graph
  for(int i = 0; i < e; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); 
    adj[v].push_back(u); 
  }
  return 0;
}