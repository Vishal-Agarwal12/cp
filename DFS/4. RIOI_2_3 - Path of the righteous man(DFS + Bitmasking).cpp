#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using ll = long long;
using maxheap = priority_queue<ll>; // maxheap
using minheap = priority_queue<ll, vector<ll>, greater<ll>>; // minheap
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sort_and_unique(a) \
    sort(all(a));          \
    (a).resize(unique(all(a)) - (a).begin())
#define minv(a) *min_element(all(a))
#define maxv(a) *max_element(all(a))
#define pb push_back
#define eb emplace_back
#define fi first
#define nl '\n'
#define se second
#define ins insert
#define sz(x) ((int)(x).size())
#define pw(x) (1LL << (x))
#define setbits(x) __builtin_popcountll(x)
const ll Mod = 998244353;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> g(n, vector<int> (n));
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cin>>g[i][j];
    }

    int sx, sy, ex, ey;
    cin>>sx>>sy;
    cin>>ex>>ey;

    vector<vector<vector<int>>> dp(n, vector<vector<int>> (n, vector<int> (1024)));

    auto isvalid = [&](int x, int y) {
        return x>=0 && x<n && y>=0 && y<n;
    };

    int ans = 10;

    auto dfs = [&](auto &&self, int x, int y, int mask) -> void {

        dp[x][y][mask] = 1;

        for(int i=0;i<4;i++) {
            int nx = x+dx[i], ny = y+dy[i];

            if(isvalid(nx, ny)) {
                int newmask = (mask | (1<<g[nx][ny]));

                if(!dp[nx][ny][newmask]) {
                    dp[nx][ny][newmask] = 1;
                    if(nx == ex && ny == ey) {
                        ans = min(ans, __builtin_popcount(newmask));
                    }
                    self(self, nx, ny, newmask);
                }
            }
        }
    };

    dfs(dfs, sx, sy, (1<<g[sx][sy]));
    cout<<ans<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
