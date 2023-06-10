#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2e5;

int N, sz[maxN + 1], x;
vector<int> G[maxN + 1];

void dfs(int u)
{
    sz[u] = 1;
    for (int v : G[u])
    {
        dfs(v);
        sz[u] += sz[v];
    }
    return;
}

int main()
{
    cin >> N;
    for (int i = 2; i <= N; i++)
    {
        cin >> x;
        G[x].push_back(i);
    }

    dfs(1);

    for (int i = 1; i <= N; i++)
    {
        cout << sz[i] - 1;
        cout << ((i == N) ? '\n' : ' ');
    }

    return 0;
}
