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
    char g[n][m];
    vector<vector<ll>> canmove(n, vector<ll> (m));
    vector<vector<bool>> vis(n, vector<bool> (m));

    ll sx, sy;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];
            if(g[i][j] == '#') {
                vis[i][j] = true;
            }
            else if(g[i][j] == 'L') {
                sx = i, sy = j;
            }
        }
    }

    auto isvalid = [&](ll x, ll y) {
        return x>=0 && x<n && y>=0 && y<m;
    };

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            for(int k=0;k<4;k++) {
                ll x = i+dx[k], y = j+dy[k];
                if(isvalid(x, y) && !vis[x][y] ) canmove[i][j]++;
            }
        }
    }
    canmove[sx][sy] = 0;
    // cout<<canmove;
    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;

    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        ll x = top.fi, y = top.se;
        for(int i=0;i<4;i++) {
            ll xx = x+dx[i], yy = y+dy[i];
            
            if(isvalid(xx, yy) && !vis[xx][yy] && g[xx][yy] != '#') {
                canmove[xx][yy]--;
                if(canmove[xx][yy] <= 1) {
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                    g[xx][yy]='+';
                }
            }
        }   
    }

    // cout<<canmove;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) cout<<g[i][j];
        cout<<nl;
    }
    
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
