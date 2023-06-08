#include <bits/stdc++.h>

using namespace std;
const int maxN = 1e5 + 1;

int N, M, u, v;
bool possible, vis[maxN], color[maxN];
vector<int> graph[maxN];

void dfs(int currentVertex, int parentVertex = 0)
{
    for (int node : graph[currentVertex])
    {
        if (node != parentVertex)
        {
            if (!vis[node])
            {
                color[node] = !color[currentVertex];
                vis[node] = true;
                dfs(node, currentVertex);
            }
            else
            {
                if (color[node] == color[currentVertex])
                    possible = false;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    possible = true;
    for (int i = 1; i <= N; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            dfs(i);
        }
    }

    if (!possible)
        printf("IMPOSSIBLE\n");
    else
        for (int i = 1; i <= N; i++)
            printf("%d%c", (color[i] ? 1 : 2), (" \n")[i == N]);
}
