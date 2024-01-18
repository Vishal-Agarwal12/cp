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

ll dx[] = {0, 0, 1, -1};
ll dy[] = {1, -1, 0, 0};

void solve()
{
    ll n, m;
    cin>>n>>m;

    ll xe, ye, xs, ys;
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    vector<vector<ll>> forest(n, vector<ll> (m, 0));
    vector<vector<ll>> dis(n, vector<ll> (m, 0));

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            char c;
            cin>>c;
            if(c == 'E') {
                xe = i, ye = j;
            }
            else if(c == 'S') {
                xs = i, ys = j;
            }
            else if(c == 'T') {
                vis[i][j] = true;
            }
            else forest[i][j] = c-'0';
        }
    }
    // cout<<forest;

    auto isvalid = [&](ll x, ll y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    queue<pair<ll, ll>> q;
    q.push({xe, ye});
    while(!q.empty()) {
        ll ss = q.size();
        
        for(int i=0;i<ss;i++) {
            auto top = q.front();
            q.pop();
            ll x = top.fi, y = top.se;
            vis[x][y] = true;
            for(int i=0;i<4;i++) {
                ll xx = x+dx[i], yy = y+dy[i];
                if(isvalid(xx, yy) && !vis[xx][yy]) {
                    q.push({xx, yy});
                    vis[xx][yy]  = true;
                    dis[xx][yy] = dis[x][y]+1;
                }
            }
        } 
    }
    // cout<<dis;
    // cout<<forest;
    ll ans = 0;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(dis[i][j] <= dis[xs][ys] && vis[i][j]) ans += forest[i][j];
        }
    }

    cout<<ans<<endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
