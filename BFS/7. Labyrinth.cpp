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

    ll sx, sy, ex, ey;
    vector<vector<bool>> vis(n+1, vector<bool> (m+1));
    vector<vector<ll>> dis(n+1, vector<ll> (m+1));
    vector<vector<char>> par(n+1, vector<char> (m+1));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            char c;
            cin>>c;
            if(c == '#') vis[i][j] = true;
            else if(c == 'A') sx = i, sy = j;
            else if(c == 'B') ex = i, ey = j;
        }
    }   

    auto isvalid = [&](ll x, ll y) {
        return x>=1 && x<=n && y>=1 && y<=m;
    };

    queue<pair<ll, ll>> q;
    q.push({sx, sy});
    vis[sx][sy] = true;
    par[sx][sy] = 'S';

    while(!q.empty()){
        auto top = q.front();
        q.pop();
        ll x = top.fi, y = top.se;
        for(int i=0;i<4;i++) {
            ll xx = x+dx[i], yy = y+dy[i];
            if(isvalid(xx, yy) && !vis[xx][yy]) {
                q.push({xx, yy});
                vis[xx][yy] = true;
                dis[xx][yy] = dis[x][y]+1;

                if(i==0) par[xx][yy] = 'U';
                else if(i==1) par[xx][yy] = 'D';
                else if(i==2) par[xx][yy] = 'L';
                else par[xx][yy] = 'R';
            }
        }
    }    
    // cout<<dis;
    // cout<<par;

    vector<char> ans;
    ll x1=ex, y1=ey;
    for(int i=dis[ex][ey];i>=1;i--) {
        ans.pb(par[x1][y1]);
        if(par[x1][y1] == 'U') x1++;
        else if(par[x1][y1] == 'R') y1--;
        else if(par[x1][y1] == 'D') x1--;
        else if(par[x1][y1] == 'L') y1++;
    }
    
    reverse(all(ans));
    if(dis[ex][ey] == 0) {
        cout<<"NO";
    }
    else {
        cout<<"YES"<<nl;
        cout<<ans.size()<<nl;
        for(auto x: ans) cout<<x;
    }
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
