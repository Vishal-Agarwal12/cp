#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int
 
int n, m;
vector<vector<int>> g;
int INF = 1e15;
int q;
 
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    // Read the number of vertices (n), number of edges (m), and number of queries (q)
    cin >> n >> m >> q;
 
    // Resize the adjacency matrix to accommodate the vertices
    g.resize(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        g[i].resize(n + 1);
    }
 
    // Initialize the adjacency matrix with infinity values
    for (int i = 1; i <= n; ++i)
    {
        for (int j = i + 1; j <= n; ++j)
        {
            g[i][j] = g[j][i] = INF;
        }
    }
 
    // Read the edges and their weights, and update the adjacency matrix
    for (int i = 0; i < m; ++i)
    {
        int u, v, c;
        cin >> u >> v >> c;
        g[u][v] = g[v][u] = min(g[u][v], c);
    }
 
    // Run the Floyd-Warshall algorithm to find the shortest paths between all pairs of vertices
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
 
    // Process the queries and print the shortest distances
    for (int i = 0; i < q; ++i)
    {
        int u, v;
        cin >> u >> v;
        if (g[u][v] == INF)
            g[u][v] = -1;
        cout << g[u][v] << endl;
    }
}
