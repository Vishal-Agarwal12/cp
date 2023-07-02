https://atcoder.jp/contests/abc308/tasks/abc308_d


#include <bits/stdc++.h>
using namespace std;

int n, m;
char s[2000][2000];
bool vis[2000][2000];
map<char, char> mp;
int f;

void dfs(int x, int y)
{
    if (vis[x][y])
        return;
    if (x == n && y == m)
        f = 1;
    vis[x][y] = 1;
    if (x + 1 <= n && mp[s[x][y]] == s[x + 1][y])
        dfs(x + 1, y);
    if (x - 1 >= 1 && mp[s[x][y]] == s[x - 1][y])
        dfs(x - 1, y);
    if (y + 1 <= m && mp[s[x][y]] == s[x][y + 1])
        dfs(x, y + 1);
    if (y - 1 >= 1 && mp[s[x][y]] == s[x][y - 1])
        dfs(x, y - 1);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> s[i][j];

    mp['s'] = 'n';
    mp['n'] = 'u';
    mp['u'] = 'k';
    mp['k'] = 'e';
    mp['e'] = 's';

    if (s[1][1] == 's')
        dfs(1, 1);

    puts(f ? "Yes" : "No");

    return 0;
}
