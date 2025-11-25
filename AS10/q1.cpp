#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V; 
    vector<vector<int>> adjMatrix;
    vector<vector<int>> adjList;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, 0));
        adjList.resize(V);
    }

    void addEdge(int u, int v) {
        
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; 

   
        adjList[u].push_back(v);
        adjList[v].push_back(u); 
    }

    void printAdjMatrix() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++)
                cout << adjMatrix[i][j] << " ";
            cout << endl;
        }
    }

    void printAdjList() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int v : adjList[i])
                cout << v << " ";
            cout << endl;
        }
    }

    int degree(int v) {
        return adjList[v].size();
    }

    int numEdges() {
        int count = 0;
        for (int i = 0; i < V; i++)
            count += adjList[i].size();
        return count / 2; 
    }

    void adjacentVertices(int v) {
        cout << "Vertices adjacent to " << v << ": ";
        for (int u : adjList[v])
            cout << u << " ";
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

    g.printAdjMatrix();
    g.printAdjList();
    cout << "Degree of vertex 1: " << g.degree(1) << endl;
    cout << "Number of edges: " << g.numEdges() << endl;
    g.adjacentVertices(1);

    return 0;
}
