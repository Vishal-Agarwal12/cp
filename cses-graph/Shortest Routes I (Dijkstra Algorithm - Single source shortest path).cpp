#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;
typedef long long ll;
const int maxN = 1e5;

struct Edge
{
    int v;
    ll w;
};

struct Node
{
    int id;
    ll dist;
    friend bool operator<(const Node &a, const Node &b)
    {
        return a.dist > b.dist;
    }
};

int N, M, a, b;
ll dist[maxN + 1], c;
vector<Edge> G[maxN + 1];
priority_queue<Node> Q;

int main()
{
    // Read the number of nodes (N) and edges (M)
    cin >> N >> M;

    // Read the edges of the graph
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    // Initialize the distances array with a large value
    memset(dist, 0x3f, sizeof(dist));

    // Set the distance of the source node to 0
    dist[1] = 0;

    // Push the source node to the priority queue
    Q.push({1, 0});

    // Dijkstra's algorithm
    while (!Q.empty())
    {
        // Extract the node with the minimum distance
        ll d = Q.top().dist;
        int u = Q.top().id;
        Q.pop();

        // If the extracted node has already been processed, skip it
        if (d > dist[u])
            continue;

        // Relax all the outgoing edges from the extracted node
        for (Edge e : G[u])
        {
            if (dist[e.v] > d + e.w)
            {
                // Update the distance if a shorter path is found
                dist[e.v] = d + e.w;
                // Push the updated node to the priority queue
                Q.push({e.v, d + e.w});
            }
        }
    }

    // Print the shortest distances from the source node to all nodes
    for (int i = 1; i <= N; i++)
        cout << dist[i] << (i == N ? "\n" : " ");

    return 0;
}
