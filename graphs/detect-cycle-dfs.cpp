#include<iostream>
#include<vector>

using namespace std;
 
class Solution {
    private:
        bool checkForCycle(int currentNode, int parent, vector<int> &visited, vector<int> adj[]) {
            visited[currentNode] = 1;
            for (auto neighborNode : adj[currentNode]) {
                // current neighbor node is unvisited
                if (visited[neighborNode] == 0) {
                    // here we pass the current node as parent
                    // of the node to be visited next
                    if (checkForCycle(neighborNode, currentNode, visited, adj))
                        return true;
                // current neighbor node is visited
                } else {
                    if (neighborNode != parent) {
                        return true;
                    }
                }
            }

            return false;
        }
 
    public:
        bool isCyclePresent(int V, vector<int> adjList[]) {
            vector<int> visited(V+1, 0);
            /**
             * traverse complete adjacency list to find
             * out if any node is part of a cycle
             */
            for (int currentNode = 0; currentNode < V; currentNode++) {
                if (visited[currentNode] == 0) {
                    if (checkForCycle(currentNode, -1, visited, adjList))
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
    bool ans = obj.isCyclePresent(noOfVertices, adjList);

    if (ans) {
        cout << "Cycle detected using DFS!";
    } else {
        cout << "Cycle not detected using DFS!";
    }

    return 0;
}