// In this problem for finding the Single source Longest path , we can convert all edges to negative weight and then find the shortest path using Bellman Ford Algorithm

// Bellman For Algorithm is used to detect if there is not a negative cycle in the code 

// we can still print the longest score if any path from vertex 1 to N does not involves negative cycle but are in other vertices .

#include <bits/stdc++.h>
using namespace std;

const long long inf = 1e17;
const long long ninf = -1e17;
struct custom
{
    int from;
    int to;
    long long weight;
};

int32_t main()
{
    ios_base::sync_with_stdio(false);

    // Read the number of vertices (n) and edges (m)
    int n, m;
    cin >> n >> m;

    vector<custom> edges;
    // Read the edges and store them in the vector
    for (int i = 0; i < m; i++)
    {
        custom input;
        cin >> input.from >> input.to >> input.weight;
        input.weight *= -1; // Negate the weight for finding the longest path
        edges.push_back(input);
    }

    vector<long long> dist(n + 1, inf);
    dist[1] = 0;

    // Bellman-Ford algorithm
    for (int i = 0; i < n; i++)
    {
        for (auto e : edges)
        {
            int u = e.from, v = e.to;
            long long w = e.weight;

            // Relax the edge (u, v)
            if (dist[u] == inf)
                continue;
            dist[v] = min(dist[v], dist[u] + w);
            dist[v] = max(dist[v], ninf); // Ensure the values don't overflow
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (auto e : edges)
        {
            int u = e.from, v = e.to;
            long long w = e.weight;

            // Check for negative-weight cycles
            if (dist[u] == inf)
                continue;
            dist[v] = max(dist[v], ninf);
            if (dist[v] > dist[u] + w)
                dist[v] = ninf;
        }
    }

    cout << '\n';

    // Print the longest path from the source (1) to the destination (n)
    if (dist[n] == ninf or dist[n] == inf)
    {
        cout << -1;
    }
    else
    {
        cout << -1 * dist[n];
    }
    cout << '\n';
    return 0;
}
