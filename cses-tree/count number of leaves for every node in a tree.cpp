// https://codeforces.com/contest/1843/problem/D

#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<vector<int>> &g, vector<long long> &leaves)
{
    for (auto child : g[node])
    {
        if (child != parent)
        {
            dfs(child, node, g, leaves);
            leaves[node] += leaves[child];
        }
    }
    if (!leaves[node])
        leaves[node]++;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        vector<vector<int>> g(n + 1);
        for (int i = 1; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        vector<long long> leaves(n + 1, 0);
        dfs(1, 0, g, leaves);

        int q;
        cin >> q;
        while (q--)
        {
            int a, b;
            cin >> a >> b;
            cout << leaves[a] * leaves[b] << "\n";
        }
    }
}
