#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Class to represent a disjoint set
class DisjointSet {
private:
    vector<int> parent, rank;

public:
    DisjointSet(int v);
    int find(int u);
    void unionSets(int u, int v);
};

DisjointSet::DisjointSet(int v) {
    parent.resize(v);
    rank.resize(v, 0);
    for (int i = 0; i < v; i++)
        parent[i] = i;
}

int DisjointSet::find(int u) {
    if (parent[u] == u)
        return u;
    parent[u] = find(parent[u]); // Path compression
    return parent[u];
}

void DisjointSet::unionSets(int u, int v) {
    int uRoot = find(u);
    int vRoot = find(v);

    if (rank[uRoot] > rank[vRoot])
        parent[vRoot] = uRoot;
    else if (rank[vRoot] > rank[uRoot])
        parent[uRoot] = vRoot;
    else {
        parent[vRoot] = uRoot;
        rank[uRoot]++;
    }
}

class Kruskal_Algo {
private:
    int v;
    vector<Edge> result;

public:
    Kruskal_Algo(int v);
    static bool compare(const Edge& e1, const Edge& e2);
    vector<Edge> kruskal_MST(vector<Edge>& edges);
};
Kruskal_Algo::Kruskal_Algo(int v) : v(v) {}

bool Kruskal_Algo::compare(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

vector<Edge> Kruskal_Algo::kruskal_MST(vector<Edge>& edges) {
    result.clear();
    sort(edges.begin(), edges.end(), compare); // Sort edges in non-decreasing order of weights
    DisjointSet ds(v);
    for (int i = 0; i < edges.size(); i++) {
        int src = edges[i].src;
        int dest = edges[i].dest;

        int srcRoot = ds.find(src);
        int destRoot = ds.find(dest);

        if (srcRoot != destRoot) { // Check if including the edge forms a cycle
            result.push_back(edges[i]); // Add the edge to the result
            ds.unionSets(srcRoot, destRoot); // Merge the two sets
        }
    }

    return result;
}

// Main function
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<Edge> edges(E);
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        cout << "Enter source: ";
        cin >> edges[i].src;
        cout << "Enter destination: ";
        cin >> edges[i].dest;
        cout << "Enter the Weight: ";
        cin >> edges[i].weight;
    }

    Kruskal_Algo obj(V);
    vector<Edge> MST = obj.kruskal_MST(edges);

    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < MST.size(); ++i) {
        cout << MST[i].src << " -- " << MST[i].dest << " : " << MST[i].weight << "\n";
    }

    getch();
    return 0;
}

