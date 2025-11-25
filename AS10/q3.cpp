#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

    void DFSUtil(int v, vector<bool> &visited) {
        visited[v] = true;
        cout << v << " ";

        for (int u : adjList[v]) {
            if (!visited[u])
                DFSUtil(u, visited);
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void DFS(int start) {
        vector<bool> visited(V, false);
        cout << "DFS traversal starting from vertex " << start << ": ";
        DFSUtil(start, visited);
        cout << endl;
    }
};

int main() {
    Graph g(5);
    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.DFS(0);
    return 0;
}
