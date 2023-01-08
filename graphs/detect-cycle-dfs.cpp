#include<iostream>
#include<vector>

using namespace std;
 
class Solution {
  bool checkForCycle(int node, int parent, vector<int> &visited, vector<int> adj[]) {
    visited[node] = 1;
    for (auto it: adj[node]) {
      if (visited[it] == 0) {
        // here we pass the current node as parent
        // of the node to be visited next
        if (checkForCycle(it, node, visited, adj))
          return true;
      } else if (it != parent) {
        return true;
      }
    }

    return false;
  }
 
  public:
    bool isCycle(int V, vector<int> adjList[]) {
      vector<int> visited(V + 1, 0);
      // traverse the entire adjacency list to find out
      // if any node is part of a cycle
      for (int i = 0; i < V; i++) {
        if (visited[i] == 0) {
          if (checkForCycle(i, -1, visited, adjList))
            return true;
        }
      }

      return false;
    }
};

int main() {
  int noOfVertices = 5;
  int noOfEdges = 5;
  vector<int> adjList[noOfVertices];
 
  adjList[0].push_back(1);
  adjList[1].push_back(0);
 
  adjList[1].push_back(2);
  adjList[2].push_back(1);
 
  adjList[1].push_back(4);
  adjList[4].push_back(1);
 
  adjList[4].push_back(3);
  adjList[3].push_back(4);
 
  adjList[2].push_back(3);
  adjList[3].push_back(2);
 
  Solution obj;
  bool ans = obj.isCycle(noOfVertices, adjList);
  if (ans) {
    cout << "Cycle Detected";
  } else {
    cout << "No Cycle Detected";
  }
 
  return 0;
}