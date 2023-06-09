// Wednesday 29-September-2021 00:46:05
#include <bits/stdc++.h>
//@ReetuRaj77
#define lli long long int
#define ulli unsigned long long int

#define all(x) (x).begin(), (x).end()

#define fastio                    \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)

using namespace std;

vector<int> adj[100005]; // Adjacency list to store the graph
vector<bool> visited;    // To keep track of visited vertices during topological sorting
vector<int> topo;        // To store the topological order of the vertices

void topological_order(int source)
{
    visited[source] = true;
    for (auto x : adj[source])
        if (!visited[x])
            topological_order(x);
    topo.push_back(source);
}

int main()
{
    fastio;
    int n, m;
    cin >> n >> m; // Read the number of vertices (n) and edges (m)

    visited.resize(n + 1, false); // Initialize visited vector with n+1 elements
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // Populate the adjacency list based on the input edges
    }

    topological_order(1); // Perform topological sorting starting from vertex 1
    reverse(all(topo));   // Reverse the topo vector to obtain the topological order in reverse

    vector<int> last(n + 1, -1); // To store the previous vertex in the longest path
    vector<int> lvl(n + 1, 0);   // To keep track of the level (length) of each vertex's longest path

    for (auto x : topo)
    {
        for (auto a : adj[x])
        {
            if (lvl[a] < lvl[x] + 1)
            {
                last[a] = x;          // Update the previous vertex
                lvl[a] = lvl[x] + 1;  // Update the level (length) of the longest path
            }
        }
    }

    if (last[n] == -1)
    {
        cout << "IMPOSSIBLE" << endl; // No path exists from the source to vertex n
        return 0;
    }

    int i = n;
    vector<int> answer;
    while (i != -1)
    {
        answer.push_back(i); // Store the vertices in the longest path
        i = last[i];         // Move to the previous vertex in the path
    }

    cout << answer.size() << endl; // Print the length of the longest path
    reverse(all(answer));          // Reverse the answer vector to obtain the correct order
    for (auto X : answer)
        cout << X << ' '; // Print the vertices in the longest path

    return 0;
}
