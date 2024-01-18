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
    ll n, x;
    cin>>n;

    vector<vector<ll>> adj(n+1);
    for(ll i=1;i<=n;i++) {
        for(ll j=1;j<=n;j++) {
            cin>>x;
            if(x == 1)
            adj[i].pb(j);
        }
    }
    // cout<<adj;

    for(ll i=1;i<=n;i++) {
        queue<ll> q;
        vector<bool> vis(n+1);
        q.push(i);
        vis[i] = true;
        ll moves = 0;

        bool fg = true;
        while(!q.empty()) {
            ll ss = q.size();
            moves++;

            for(int j=0;j<ss;j++) {
                ll top = q.front();
                q.pop();
                for(auto it: adj[top]) {
                    if(it == i) {
                        cout<<moves<<nl;
                        fg = false;
                        break;
                    }
                    if(!vis[it]) {
                        q.push(it);
                        vis[it] = true;
                    }
                }
                if(fg == false) break;
            }
            if(fg == false) break;
        }
        if(fg==true) cout<<"NO WAY"<<nl;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
