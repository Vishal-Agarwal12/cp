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

ll dx[] = {-1, 1, 0, 0};
ll dy[] = {0, 0, -1, 1};
void solve()
{
    ll n, m;
    cin>>n>>m;

    vector<vector<bool>> vis(n, vector<bool> (m));
    vector<vector<char>> g(n, vector<char> (m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char ch;
            cin>>ch;
            g[i][j] = ch;
            if(ch == '#') vis[i][j] = true;
        }
    }
    
    auto isvalid = [&](ll x, ll y) -> bool {
        return x>=0 && x<n && y>=0 && y<m;
    };

    ll k = 0, v = 0, fg = 0;
    auto dfs = [&](auto &&self, ll x, ll y) -> void {
        if(x == 0 || x == n-1 || y == 0 || y == m-1) fg = 1;
        vis[x][y] = true;
        if(g[x][y] == 'k') k++;
        if(g[x][y] == 'v') v++;

        for(int i=0;i<4;i++) {
            ll nx = x+dx[i], ny = y+dy[i];
            if(isvalid(nx, ny) && !vis[nx][ny] && g[nx][ny] != '#') {
                self(self, nx, ny);
            }
        }
    };

    ll sp = 0, wol = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(!vis[i][j]) {
                k = 0, v = 0, fg = 0;
                dfs(dfs, i, j);
                if(fg == 1) {
                    sp+=k;
                    wol+=v;
                }
                else if(k > v) sp+=k;
                else wol += v;
            }
        }
    }

    cout<<sp<<" "<<wol<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
