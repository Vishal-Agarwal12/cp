#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
#define int long long int

int n, m;
vector<int> degree;  // Stores the in-degrees of vertices
priority_queue<int, vector<int>, greater<int>> noInDeg;  // Stores vertices with no incoming edges
vector<vector<int>> g;  // Adjacency list representation of the graph

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    degree.resize(n + 1);

    // Build the graph and compute in-degrees
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        ++degree[v];
    }

    // Find vertices with no incoming edges and add them to the priority queue
    for (int i = 1; i <= n; ++i)
    {
        if (!degree[i])
            noInDeg.push(i);
    }

    vector<int> ans;  // Stores the topological ordering
    while (!noInDeg.empty())
    {
        int u = noInDeg.top();
        noInDeg.pop();
        ans.push_back(u);
        for (auto v : g[u])
        {
            --degree[v];
            if (!degree[v])
                noInDeg.push(v);
        }
    }

    // If the size of the topological ordering is not equal to the number of vertices, a topological ordering is not possible (cycle exists)
    if (ans.size() != n)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        // Print the topological ordering
        for (auto u : ans)
            cout << u << " ";
    }
}
