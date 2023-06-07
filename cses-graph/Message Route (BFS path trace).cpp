#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;

int shortestDistance(int start, int end, vector<int> &route)
{
    int n = graph.size() - 1;
    vector<bool> visited(n + 1, false);
    vector<int> distance(n + 1, 0);
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        if (curr == end)
        {
            // Reconstruct the route
            int node = end;
            while (node != -1)
            {
                route.push_back(node);
                node = parent[node];
            }
            reverse(route.begin(), route.end());

            return distance[curr];
        }

        for (int neighbor : graph[curr])
        {
            if (!visited[neighbor])
            {
                q.push(neighbor);
                visited[neighbor] = true;
                distance[neighbor] = distance[curr] + 1;
                parent[neighbor] = curr;
            }
        }
    }

    // If end node is not reachable from the start node
    return -1;
}

int main()
{
    int n, m;
    cin >> n >> m; // Number of nodes and edges

    graph.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // Edge from u to v
        graph[u].push_back(v);
        graph[v].push_back(u); // Add both directions for undirected graph
    }

    int start = 1, end = n;

    vector<int> route;
    int shortestDist = shortestDistance(start, end, route);
    if (shortestDist != -1)
    {
        cout << route.size() << endl;
        for (int node : route)
        {
            cout << node << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}
