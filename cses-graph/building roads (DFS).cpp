#include <iostream>
#include <vector>

using namespace std;

vector<int> cities;

void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited)
{
    visited[node] = true;
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, visited);
        }
    }
}

int countConnectedComponents(vector<vector<int>> &graph)
{
    int n = graph.size() - 1;
    vector<bool> visited(n + 1, false);
    int count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            cities.push_back(i);
            dfs(i, graph, visited);
            count++;
        }
    }

    return count;
}

int main()
{
    int n, m;
    cin >> n >> m; // Number of nodes and edges

    vector<vector<int>> graph(n + 1);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v; // Edge from u to v
        graph[u].push_back(v);
        graph[v].push_back(u); // Add both directions for undirected graph
    }

    int connectedComponents = countConnectedComponents(graph);

    cout << connectedComponents - 1 << endl;

    for (int i = 0; i < cities.size() - 1; i++)
    {
        cout << cities[i] << " " << cities[i + 1] << endl;
    }

    return 0;
}
