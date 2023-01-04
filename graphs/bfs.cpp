#include<iostream>
#include<vector>
#include<queue>
using namespace std;
 
class Graph {
public:
  static void BFS(int V, vector<int> adj[]);
};
 
void addEdge(vector<int> adj[], int v, int w) {
  adj[v].push_back(w);
  adj[w].push_back(v);
}
 
// In BFS we traverse adjacent nodes first
void Graph::BFS(int V, vector<int> adj[]) {
  // queue to perform BFS
  queue<int> q;

  // mark all the vertices as not visited
  vector<int> visited(V+1, 0);

  // this vector has the bfs of the graph
  vector<int> bfs;
 
  // This loop ensures that we pick each
  // node & check if it's visited or not.
  // Any node found as not visited implies
  // its part of a different component
  for (int i = 1; i <= V; i++) {
    // if node i is not touched yet
    if (visited[i] == 0) {
      // bfs starts from first node inserted to queue
      q.push(i);
      visited[i] = 1;
      while (!q.empty()) {
        int currNode = q.front();
        q.pop();
        bfs.push_back(currNode);
        // using adjacency list to visit all neighbour nodes
        // of each node
        for (auto neighbor : adj[currNode]) {
          if (visited[neighbor] == 0) {
            q.push(neighbor);
            visited[neighbor] = 1;
          }
        }
      }
    }
  }
 
  for (int i = 0; i < bfs.size(); i++) {
    cout << bfs[i] << " ";
  }
}
 
int main() {
  int V = 5;
  // It's an array of int vectors
  // Array is of size V+1
  vector<int> adj[V+1];

  addEdge(adj, 0, 1);
  addEdge(adj, 0, 2);
  addEdge(adj, 0, 3);
  addEdge(adj, 2, 4);
 
  cout << "Breadth First Traversal: \n";
  Graph::BFS(V, adj);

  return 0;
}
 