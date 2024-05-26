#include <bits/stdc++.h>
using namespace std;

void printPath(vector<int> &parent, int j) {
    if (parent[j] == -1){
        cout<<j+1<<" ";
        return;
    }
    cout << j + 1 << " ";
    printPath(parent, parent[j]);
}

void bellman_ford(vector<vector<int>>& edges, int V, int s) {
    vector<int> dist(V, INT_MAX);
    dist[s] = 0;
    vector<int> parent(V, -1);

    for (int i = 0; i < V - 1; i++) {
        for (auto &itr : edges) {
            int src = itr[0];
            int dest = itr[1];
            int wt = itr[2];

            if (dist[src] != INT_MAX && dist[src] + wt < dist[dest]) {
                dist[dest] = dist[src] + wt;
                parent[dest] = src;
            }
        }
    }

    // Check for negative-weight cycles
    for (auto &itr : edges) {
        int src = itr[0];
        int dest = itr[1];
        int wt = itr[2];
        if (dist[src] != INT_MAX && dist[src] + wt < dist[dest]) {
            cout << "Graph contains a negative-weight cycle" << endl;
            return;
        }
    }

    // Printing the result
    for (int i = 0; i < V; i++) {
            if (dist[i] == INT_MAX) {
                cout << "Infinity";
            } else {
                //cout << i + 1<<" ";
                printPath(parent, i);
                cout <<":"<< dist[i];
                //cout << s + 1 << " ";
            }
            cout << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> edges;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                edges.push_back({i, j, graph[i][j]});
            }
        }
    }

    int src;
    cin >> src;
    src--; // Convert to 0-based index

    bellman_ford(edges, n, src);

    return 0;
}
