#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void BFS(int start) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal starting from vertex " << start << ": ";

        while (!q.empty()) {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adjList[v]) {
                if (!visited[u]) {
                    visited[u] = true;
                    q.push(u);
                }
            }
        }
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

    g.BFS(0);
    return 0;
}
