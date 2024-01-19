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
ll dy[] = {0, 0, 1, -1};

void solve()
{
    ll n, m, k;
    cin>>n>>m;
    cin>>k;

    queue<pair<ll, ll>> q;
    vector<vector<ll>> vis(n+1, vector<ll> (m+1));
    vector<vector<ll>> dis(n+1, vector<ll> (m+1));

    for(int i=0;i<k;i++) {
        ll x,y;
        cin>>x>>y;
        q.push({x, y});
        vis[x][y] = true;
        dis[x][y]=1;
    }

    auto isvalid = [&](ll x, ll y)-> bool {
        return x>=1 && x<=n && y>=1 && y<=m;
    };
    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        ll x = top.fi, y = top.se;
        for(int i=0;i<4;i++) {
            ll xx = x+dx[i], yy = y+dy[i];
            if(isvalid(xx, yy) && !vis[xx][yy]) {
                q.push({xx, yy});
                vis[xx][yy] = true;
                dis[xx][yy] = dis[x][y] + 1;
            }
        }
    }

    ll mn = 0;
    ll p1 = 0, p2 = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(dis[i][j] > mn) {
                mn = dis[i][j];
                p1 = i, p2 = j;
            }
        }
    }
    cout<<p1<<" "<<p2<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    solve();

    return 0;
}
