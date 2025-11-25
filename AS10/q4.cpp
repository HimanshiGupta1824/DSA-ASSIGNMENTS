#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int u, v, w;
};

class Graph {
    vector<int> parent, rank;
public:
   Graph(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if(parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xRoot = find(x);
        int yRoot = find(y);
        if(rank[xRoot] < rank[yRoot])
            parent[xRoot] = yRoot;
        else if(rank[xRoot] > rank[yRoot])
            parent[yRoot] = xRoot;
        else {
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
};

bool cmp(Edge a, Edge b) {
    return a.w < b.w;
}

void kruskalMST(int V, vector<Edge> &edges) {
    sort(edges.begin(), edges.end(), cmp);
    Graph ds(V);

    cout << "Edges in Kruskal's MST:\n";
    int mst_weight = 0;

    for(auto e : edges) {
        if(ds.find(e.u) != ds.find(e.v)) {
            cout << e.u << " - " << e.v << " (weight: " << e.w << ")\n";
            mst_weight += e.w;
            ds.unite(e.u, e.v);
        }
    }

    cout << "Total weight of MST: " << mst_weight << endl;
}

int main() {
    int V = 4;
    vector<Edge> edges = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5},
        {1, 3, 15}, {2, 3, 4}
    };

    kruskalMST(V, edges);
    return 0;
}
