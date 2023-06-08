#include <bits/stdc++.h>
#define int long long int

#define all(x) (x).begin(), (x).end()

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)

using namespace std;

const int INF = 1e17;

signed main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        edges.push_back({x, y, z});
    }

    int x;                     // Vertex used to detect negative cycle
    vector<int> dist(n + 1);   // Stores the shortest distance from the source to each vertex
    vector<int> par(n + 1, 0); // Stores the parent vertex for each vertex

    // Bellman-Ford Algorithm
    for (int i = 0; i < n; i++)
    {
        x = -1;
        for (auto e : edges)
        {
            int u, w, v;
            tie(u, v, w) = e;
            if (dist[u] == INF)
                continue;
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                x = v;
            }
        }
    }

    if (x == -1)
        cout << "NO" << endl; // No negative cycle found
    else
    {
        cout << "YES" << endl; // Negative cycle found
        int y = x;

        // Backtrack to find a vertex in the negative cycle
        for (int i = 0; i < n; i++)
            y = par[y];

        vector<int> path;
        // Construct the negative cycle by backtracking from the cycle-start vertex
        for (int current = y;; current = par[current])
        {
            path.push_back(current);
            if (current == y && path.size() > 1)
                break;
        }
        reverse(all(path)); // Reverse the path to get the correct order

        // Print the vertices in the negative cycle
        for (auto x : path)
            cout << x << " ";
    }
    return 0;
}
