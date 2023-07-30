#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int dest, weight;
};

class DijkstraAlgorithm {
private:
    vector<vector<Edge> > graph;
    int V;

public:
	
    DijkstraAlgorithm(int numVertices);
    void addEdge(int src, int dest, int weight);
    vector<int> findShortestPaths(int src);
};

DijkstraAlgorithm::DijkstraAlgorithm(int numVertices) : V(numVertices) {
    graph.resize(V);
}

void DijkstraAlgorithm::addEdge(int src, int dest, int weight) {
    graph[src].push_back({dest, weight});
}

vector<int> DijkstraAlgorithm::findShortestPaths(int src) {
	
	
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        for (int i = 0; i < graph[u].size(); i++) {
            int v = graph[u][i].dest;
            int weight = graph[u][i].weight;


            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    DijkstraAlgorithm dijkstra(V);
     int src, dest, weight;
    cout << "Enter the source, destination, and weight of each edge:\n";
    for (int i = 0; i < E; i++) {
        cout<<"Enter the source : ";
        cin >> src ;
        cout<<"Enter the destination : ";
		cin>> dest;
		cout<<"Enter the Weight : ";
		cin>> weight;
        dijkstra.addEdge(src, dest, weight);
    }

     src=0;
    cout << "Enter the source vertex: ";
    cin >> src;

    vector<int> shortestPaths = dijkstra.findShortestPaths(src);

    cout << "Shortest Paths from vertex " << src << ":\n";
    for (int i = 0; i < V; i++) {
        cout << "Vertex " << i << ": ";
        if (shortestPaths[i] == INT_MAX)
            cout << "No path";
        else
            cout << shortestPaths[i];
        cout << endl;
    }

    return 0;
}

