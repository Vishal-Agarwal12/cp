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

int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, -1, 1, 1, -1, 1, -1};

void solve(int h, int w, int cs)
{
    vector<vector<int>> g(h, vector<int> (w));
    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            char ch;
            cin>>ch;
            g[i][j] = (ch-'A');
        }
    }

    auto isvalid = [&](int x, int y) {
        return x>=0 && x<h && y>=0 && y<w;
    };

    int ans = 0;
    auto bfs = [&](int x, int y) {
        queue<pair<int, int>> q;
        q.push({x, y});
        vector<vector<bool>> vis(h, vector<bool> (w));

        while(!q.empty()) {
            int ss = q.size();
            for(int i=0;i<ss;i++) {
                auto top = q.front();
                q.pop();

                int x = top.fi, y = top.se;
                vis[x][y] = true;
                for(int j=0;j<8;j++) {
                    int nx = x+dx[j], ny = y+dy[j];
                    if(isvalid(nx, ny) && !vis[nx][ny] && g[x][y]+1 == g[nx][ny]) {
                        ans = max(ans, g[nx][ny]+1);
                        vis[nx][ny] = true;
                        q.push({nx, ny});
                    }
                }
            }
        }
    };

    for(int i=0;i<h;i++) {
        for(int j=0;j<w;j++) {
            if(g[i][j] == 0) {
                bfs(i, j);
                ans = max(1, ans);
            }
        }
    }
    
    cout<<"Case "<<cs<<": "<<ans<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    int h, w, cs = 1;
    while(true) {
        cin>>h>>w;
        if(h == 0 && w == 0) break;
        solve(h, w, cs);
        cs++;
    }

    return 0;
}

/*
1 1
B
1 2
AA
1 1
A
1 1
B
5 3
ABF
CFG
OQP
DCB
PQA
0 0
*/
