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

    vector<vector<char>> g(n, vector<char> (m));
    vector<vector<bool>> vis(n, vector<bool> (m));
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            cin>>g[i][j];
            if(g[i][j] == '#') vis[i][j] = true;
        }
    } 

    ll c = 0, sx, sy;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(i==0 || j==0 || i==n-1 || j==m-1) {
                if(g[i][j] == '.') {
                    c++;
                    sx = i, sy = j;
                }
            }
        }
    }
    if(c!=2) {
        cout<<"invalid"<<nl;
        return;
    }

    auto isvalid = [&](ll x, ll y) {
        return x>=0 && x<n && y>=0 && y<m;
    };
    auto onborder = [&](ll x, ll y) {
        return x==0 || x==n-1 || y==0 || y==m-1;
    };

    bool fg = false;
    
    auto dfs = [&](auto &&self, ll x, ll y) -> void {
        vis[x][y] = true;
        // cout<<"x: "<<x<<" "<<"y: "<<y<<nl;
        for(int i=0;i<4;i++) {
            ll nx = x+dx[i], ny = y+dy[i];
            if(isvalid(nx, ny) && !vis[nx][ny]) {
                if(onborder(nx, ny) && (nx!=sx || ny!=sy)) {
                    fg = true;
                }
                self(self, nx, ny);
            }
        }
    };

    dfs(dfs, sx, sy); 
    // cout<<"sx: "<<sx<<" "<<"sy: "<<sy<<nl;

    if(fg==true) cout<<"valid"<<nl;
    else cout<<"invalid"<<nl;
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
