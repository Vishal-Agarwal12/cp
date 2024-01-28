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

void solve()
{
    ll n, m;
    cin>>n>>m;

    vector<vector<ll>> adj(n+1);
    vector<pair<ll, ll>> edg;
    for(int i=0;i<m;i++) {
        ll u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
        edg.push_back({u, v});
    }

    vector<ll> col(n+1);
    for(int i=1;i<=n;i++) {
        col[i] = -1;
    }

    queue<ll> q;
    q.push(1);
    col[1] = 0;

    while(!q.empty()) {
        ll ss = q.size();
        for(int i=0;i<ss;i++) {
            ll top = q.front();
            q.pop();
            for(auto it: adj[top]) {
                if(col[it] == -1) {
                    col[it] = 1^col[top];
                    q.push(it);
                }
                else if(col[it] == col[top]) {
                    cout<<"NO"<<nl;
                    return;
                }
            }
        }
    }

    cout<<"YES"<<nl;
    for(int i=0;i<m;i++) {
        if(col[edg[i].fi] == 0 && col[edg[i].se] == 1) {
            cout<<1;
        }
        else cout<<0;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
