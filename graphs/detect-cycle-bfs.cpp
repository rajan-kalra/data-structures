#include <iostream>
#include <queue>
using namespace std;
 
class Solution {
  public:
    bool checkForCycle(int sourceNode, int V, vector<int> adjList[], vector<int> &visited) {
      // Create a queue for BFS
      // this queue has the node & its parent
      queue<pair<int, int>> q;

      visited[sourceNode] = true;

      // first node has parent as -1
      q.push({sourceNode, -1});

      while (q.empty() == false) {
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto it : adjList[node]) {
          if (!visited[it]) {
            visited[it] = true;
            q.push({it, node});
          } else if (parent != it) {
            return true;
          }
        }
      }

      return false;
    }
 
    bool isCycle(int V, vector<int> adjList[]) {
      vector<int> visited(V - 1, 0);
      // traverse the entire adjacency list to check
      // no node is part of any cycle
      for (int i = 1; i <= V; i++) {
        if (visited[i] == 0) {
          if (checkForCycle(i, V, adjList, visited))
            return true;
        }
      }

      return false;
    }
};
 
void addEdge(vector<int> adj[],int u,int v) {
  adj[u].push_back(v);
  adj[v].push_back(u);
}
 
int main() {
  vector<int> adj[5];

  addEdge(adj,0,1);
  addEdge(adj,0,2);
  addEdge(adj,2,3);
  addEdge(adj,1,3);
  addEdge(adj,2,4);

  Solution obj;
  int num=obj.isCycle(5, adj);
  if(num==1)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  return 0;
}