#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an edge in the graph
struct Edge {
    int src, dest, weight;
};

// Structure to represent a disjoint set
struct DisjointSet {
    vector<int> parent, rank;
    
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        
        // Initially, all elements are in different sets and have rank 0
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
    
    // Find the parent of a set
    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }
    
    // Union of two sets
    void unionSets(int u, int v) {
        int uRoot = find(u);
        int vRoot = find(v);
        
        if (rank[uRoot] < rank[vRoot]) {
            parent[uRoot] = vRoot;
        } else if (rank[uRoot] > rank[vRoot]) {
            parent[vRoot] = uRoot;
        } else {
            parent[vRoot] = uRoot;
            rank[uRoot]++;
        }
    }
};

// Comparator function to sort edges based on their weights
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the Minimum Spanning Tree using Kruskal's algorithm
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
    vector<Edge> result;
    
    // Sort the edges in non-decreasing order of their weights
    sort(edges.begin(), edges.end(), compareEdges);
    
    DisjointSet ds(V);
    
    // Process each edge in sorted order
    for (const auto& edge : edges) {
        int src = edge.src;
        int dest = edge.dest;
        
        int srcRoot = ds.find(src);
        int destRoot = ds.find(dest);
        
        // If including this edge does not create a cycle, include it in the MST
        if (srcRoot != destRoot) {
            result.push_back(edge);
            ds.unionSets(srcRoot, destRoot);
        }
    }
    
    return result;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    
    vector<Edge> edges(E);
    
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }
    
    vector<Edge> MST = kruskalMST(edges, V);
    
    cout << "Minimum Spanning Tree:\n";
    for (const auto& edge : MST) {
        cout << edge.src << " -- " << edge.dest << " : " << edge.weight << "\n";
    }
    
    return 0;
}







