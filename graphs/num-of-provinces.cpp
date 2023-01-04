#include <iostream>
#include <vector>
#include <queue>

using namespace std;
 
// BFS based solution
class SolutionBFS {
public:
 
  /**
   * Given isConnected vector of vectors is like adjacency
   * matrix depicting connected cities.
   **/
  int findCircleNum(vector<vector<int>>& isConnected) {
    int V = isConnected.size();

    // Generic code to change adjacency matrix to list 
    vector<int> adjList[V+1];
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        /**
         * (i==j) means (0,0) or (1,1) & so on. In
         * an n*n adjacency matrix representing n nodes
         * connections, i==j means the self loop check,
         * thus not required. i+1 & j+1 as 1 based indexed
         * nodes
         **/
        if (isConnected[i][j] == 1 && i != j) {
            adjList[i+1].push_back(j+1);
            adjList[j+1].push_back(i+1);
        }
      }
    }

    int count = 0;
    vector<int> visited(V+1, 0);
    queue<int> q;
    for (int i = 1; i <= V; i++) {
      if (visited[i] == 0) {
        /**
         * At this point we are starting with a
         * new connected component.
         */
        count++;
        q.push(i);
        visited[i] = 1;
        while (q.empty() == false) {
          int node = q.front();
          q.pop();
          for (auto it : adjList[node]) {
            if (visited[it] == 0) {
                q.push(it);
                visited[it] = 1;
            }
          }
        }
      }
    }

    return count;
  }
};
 
// DFS based solution
class SolutionDFS {
  private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjList[], vector<int>& visited) {
      // marking the node as visited
      visited[node] = 1; 
      for(auto neighbor: adjList[node]) {
        if(visited[neighbor] == 0) {
          dfs(neighbor, adjList, visited); 
        }
      }
    }
  public:
    int numProvinces(vector<vector<int>> adjMat, int V) {
      // an array of vectors
      vector<int> adjList[V]; 

      // Generic code to change adjacency matrix to list 
      for(int i = 0; i < V; i++) {
        for(int j = 0; j < V; j++) {
          /**
           * (i==j) means (0,0) or (1,1) & so on. In
           * an n*n adjacency matrix representing n nodes
           * connections, i==j means the self loop check,
           * thus not required. i+1 & j+1 as 1 based indexed
           * nodes
           **/
          if(adjMat[i][j] == 1 && i != j) {
            adjList[i].push_back(j); 
            adjList[j].push_back(i); 
          }
        }
      }
 
      vector<int> visited(V, 0);
      int count = 0; 
      for (int i = 0; i < V; i++) {
        // if the node is not visited
        if (visited[i] == 0) {
          // counter to count the number of provinces 
          count++;
          dfs(i, adjList, visited);
        }
      }

      return count;
    }
};
 
int main() {
  vector<vector<int>> adj {
                            {1, 0, 1},
                            {0, 1, 0},
                            {1, 0, 1}
                          };
 
    SolutionBFS ob;
    cout << ob.findCircleNum(adj) << endl;
 
    return 0;
}
