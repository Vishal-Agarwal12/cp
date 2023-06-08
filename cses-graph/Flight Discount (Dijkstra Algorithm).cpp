#include <bits/stdc++.h>
#define int long long
using namespace std;

#define endl '\n'
typedef long long ll;

int vis[100005];
int dis1[100005], dis2[100005];

void dijkstra(int s, int dis[], vector<pair<int, int>> adj[])
{
    priority_queue<pair<int, int>> pq;
    memset(dis, 0x3f, sizeof(dis1)); // Initialize distances to a large value
    dis[s] = 0;
    pq.push({0, s});
    memset(vis, 0, sizeof(vis));

    while (!pq.empty())
    {
        int x = pq.top().second;
        pq.pop();
        if (vis[x])
            continue;
        vis[x] = 1;
        for (auto &[y, z] : adj[x])
        {
            if (dis[x] + z < dis[y])
            {
                dis[y] = dis[x] + z;
                pq.push({-dis[y], y});
            }
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
    // cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> adj1[n + 1], adj2[n + 1];
        vector<tuple<int, int, int>> e;

        // Reading the flight routes and storing them in adjacency lists
        for (int i = 0; i < m; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            e.push_back({x, y, z});
            adj1[x].push_back({y, z});
            adj2[y].push_back({x, z}); // reverse the edges, so as to find shortest path from node n to every other node
        }

        // Running Dijkstra's algorithm to find the shortest paths from node 1
        dijkstra(1, dis1, adj1);

        // Running Dijkstra's algorithm to find the shortest paths from node n
        dijkstra(n, dis2, adj2);

        ll ans = 0x3f3f3f3f3f3f3f3f; // Initialize the answer to a large value

        // Iterating over the flight routes to find the minimum total cost
        for (auto &[x, y, z] : e)
        {
            // Calculating the total cost considering using the coupon
            ll cost = dis1[x] + dis2[y] + z / 2;

            // Updating the minimum cost if necessary
            ans = min(ans, cost);
        }

        cout << ans << endl; // Outputting the minimum total cost
    }

    return 0;
}
