#include <iostream>
#include <vector>
using namespace std;
 
/**
 * 
 * Adjacency list may look like:
 * 1 -> 2
 * 2 -> 1 4 7
 * 3 -> 5
 * 4 -> 2 6
 * 5 -> 3
 * 6 -> 4 7
 * 7 -> 2 6
 * 
 **/
 
/**
 * DFS works as follows:
 * We start DFS on a specific node say node1
 * We keep doing recursive calls on each adjacent node of node1 in the adjacency list.
 * Now when we call DFS on first adjacent node of node1, it will keep recursing on this 
 * node further & call DFS on adjacent nodes of this node node1 & so on.
 **/
 
class Solution {
  void DFS(int node, vector<int> &visited, vector<int> adjList[], vector<int> &dfs) {
    // mark the node as visited
    visited[node] = 1;

    dfs.push_back(node);
    for (auto neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited, adjList, dfs);
        }
    }
  }
 
public:
  vector<int> DFSOfGraph(int V, vector<int> adjList[]) {
    vector<int> dfs; 
    vector<int> visited(V+1, 0);
    // this loop ensures that if there are disconnected components,
    // we cover them too if one of the component is completely traversed
    for (int i = 1; i <= V; i++) {
      if (visited[i] == 0) {
        DFS(i, visited, adjList, dfs);
      }
    }

    return dfs; 
  }
};
 
void addEdge(vector<int> adj[], int u, int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
 
int main() {
  int V = 5;

  /**
   * Since we are doing 1 based indexing, we
   * take vectors of size V+1 to accomodate
   * first empty index of 0 
   **/
  vector<int> adj[V+1];

  addEdge(adj,1,2);
  addEdge(adj,1,3);
  addEdge(adj,1,4);
  addEdge(adj,1,5);
  addEdge(adj,2,4);
  addEdge(adj,2,1);
  addEdge(adj,3,1);
  addEdge(adj,4,1);
  addEdge(adj,4,2);
  addEdge(adj,5,1);

  Solution obj;
  vector<int> df;
  df = obj.DFSOfGraph(V, adj);

  for(auto it: df)
    cout << it << " ";

  return 0;
}