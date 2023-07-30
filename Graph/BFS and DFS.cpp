#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS_DFS {
private:
    int v;
    vector<int> *graph;
    vector<bool> visited;

public:
    BFS_DFS(int);
    void getdata();
    void BFS(int);
};

BFS_DFS::BFS_DFS(int V) {
    v = V;
    graph.resize(v);
    visited.resize(v, false);
}

void BFS_DFS::getdata() {
    graph[0].push_back(1);
    graph[1].push_back(0);

    graph[1].push_back(2);
    graph[2].push_back(1);

    graph[1].push_back(3);
    graph[3].push_back(1);

    graph[2].push_back(4);
    graph[4].push_back(2);

    graph[3].push_back(4);
    graph[4].push_back(3);
}

void BFS_DFS::BFS(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        start = q.front();
        cout << start << " ";
        q.pop();

        for (int i = 0; i < graph[start].size(); i++) {
            if (!visited[graph[start][i]]) {
                visited[graph[start][i]] = true;
                q.push(graph[start][i]);
            }
        }
    }
}

int main() {
    int v = 5;
    BFS_DFS obj(v);
    obj.getdata();
    obj.BFS(0);

    return 0;
}

