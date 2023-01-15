#include <iostream>
#include <climits>
using namespace std;

const int N = 100; // maximum number of nodes
int n; // number of nodes
int m; // number of edges
int w[N][N]; // weight matrix
int d[N]; // distance array
bool vis[N]; // visited array

void dijkstra(int s) {
    for (int i = 0; i < n; i++) {
        d[i] = INT_MAX;
        vis[i] = false;
    }
    d[s] = 0;

    for (int i = 0; i < n ; i++) {
        int u = -1;
        int min_d = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!vis[j] && d[j] < min_d) {
                u = j;
                min_d = d[j];
            }
        }
        if (u == -1) return;
        vis[u] = true;
        for (int v = 0; v <= n; v++) {
            if (!vis[v] && w[u][v] != INT_MAX && d[u] + w[u][v] < d[v]) {
                d[v] = d[u] + w[u][v];
            }
        }
    }
}

int main() {
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            w[i][j] = INT_MAX;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << "Enter the edges (u v weight):" << endl;
        int u, v, weight;
        cin >> u >> v >> weight;
        w[u][v] = weight;
    }

    int s;
    cout << "Enter the source node: ";
    cin >> s;

    dijkstra(s);

    cout << "Shortest distances from the source node to each node:" << endl;
    for (int i = 1; i <= n; i++) {
        cout << i << ": " << d[i] << endl;
    }

    return 0;
}