#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair<int, ll> edge;
typedef pair<ll, int> node;
const int maxN = 2e5 + 1;

int N, M, K, cnt[maxN];
vector<edge> G[maxN];
priority_queue<node, vector<node>, greater<node>> Q;

int main()
{
    // Read input values for N, M, and K
    cin >> N >> M >> K;
    
    // Read edges and their weights
    for (int i = 0, a, b, c; i < M; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back({b, c});
    }

    // Initialize priority queue with source node (node 1) and distance 0
    Q.push({0, 1});

    // Process nodes until the K-th shortest path to the destination (node N) is found
    while (!Q.empty())
    {
        // Extract the node with the smallest distance from the priority queue
        ll d = Q.top().first;
        int u = Q.top().second;
        Q.pop();

        // Increment the count of visits to node u
        cnt[u]++;

        // If the current node is the destination (node N), print the distance
        if (u == N)
        {
            cout << d << " ";

            // If the K-th shortest path is found, break out of the loop
            if (cnt[u] == K)
                break;
        }

        // If the current node has been visited fewer than or equal to K times,
        // add its neighbors to the priority queue
        if (cnt[u] <= K)
        {
            for (edge e : G[u])
            {
                int v = e.first;   // Neighbor node
                ll w = e.second;  // Weight of the edge between u and v
                Q.push({d + w, v});  // Add the neighbor node with updated distance to the priority queue
            }
        }
    }

    return 0;
}
