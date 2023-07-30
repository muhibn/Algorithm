#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

struct Edge {
    int dest, weight;
};

class PrimAlgorithm {
private:
    vector<vector<Edge> > graph; // Adjacency list representation of the graph
    int V; // Number of vertices in the graph

public:
    PrimAlgorithm(int numVertices);

    // Function to add an edge to the graph
    void addEdge(int src, int dest, int weight);

    // Function to find the minimum spanning tree (MST) of the graph using Prim's algorithm
    vector<Edge> findMST();
};

PrimAlgorithm::PrimAlgorithm(int numVertices) : V(numVertices) {
    graph.resize(V);
}

void PrimAlgorithm::addEdge(int src, int dest, int weight) {
    graph[src].push_back({ dest, weight });
    graph[dest].push_back({ src, weight });
}

vector<Edge> PrimAlgorithm::findMST() {
    vector<Edge> MST; 
    vector<bool> visited(V, false); 
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1); 
    // Start with the first vertex as the source
    int src = 0;
    key[src] = 0;

    // Find MST with V-1 edges
    for (int i = 0; i < V - 1; i++) {
        // Find the vertex with the minimum key value among the non-visited vertices
        int minKey = INT_MAX, minVertex;
        for (int v = 0; v < V; v++) {
            if (!visited[v] && key[v] < minKey) {
                minKey = key[v];
                minVertex = v;
            }
        }

        // Mark the selected vertex as visited
        visited[minVertex] = true;

        // Update the key and parent for its adjacent vertices
        for (int i = 0; i < graph[minVertex].size(); i++) {
            int v = graph[minVertex][i].dest;
            int weight = graph[minVertex][i].weight;
            if (!visited[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = minVertex;
            }
        }
    }

    // Add the edges of the MST to the result vector
    for (int i = 1; i < V; i++) {
        MST.push_back({ i, key[i] });
    }

    return MST;
}

// Main function
int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    // Create an instance of the PrimAlgorithm class
    PrimAlgorithm prim(V);

    // Prompt the user to enter the source, destination, and weight of each edge
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        int src, dest, weight;
        cin >> src >> dest >> weight;
        prim.addEdge(src, dest, weight);
    }

    // Find the minimum spanning tree (MST) of the graph using Prim's algorithm
    vector<Edge> MST = prim.findMST();

    // Print the edges of the minimum spanning tree
    cout << "Minimum Spanning Tree:\n";
    for (int i = 0; i < MST.size(); i++) {
        cout << MST[i].dest << " -- " << MST[i].weight << "\n";
    }
    
    
    getch();

    return 0;
}

