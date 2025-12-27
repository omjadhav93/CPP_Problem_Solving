#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

void floydWarshall(vector<vector<int>> &dist, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
}

int main() {
    int n, edges;
    cin >> n >> edges;   // number of nodes and edges

    // Initialize matrix with INF and 0 on diagonal
    vector<vector<int>> dist(n, vector<int>(n, INF));

    for (int i = 0; i < n; i++) dist[i][i] = 0;

    // Input edges in: u v w format
    for (int k = 0; k < edges; k++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;   // directed edge
    }

    // Run Floyd–Warshall
    floydWarshall(dist, n);

    // Print result
    cout << "\nShortest distance matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF) cout << "INF ";
            else cout << dist[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// Input:
// 4 5
// 0 1 5
// 1 2 3
// 0 3 10
// 2 3 1
// 3 0 7

// Output:
// 0 5 8 9
// 10 0 3 4
// 8 13 0 1
// 7 12 15 0
