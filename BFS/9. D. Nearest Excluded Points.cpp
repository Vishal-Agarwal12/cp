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
    ll n;
    cin>>n;

    vector<pair<ll, ll>> v;
    for(int i=0;i<n;i++) {
        ll x,y;
        cin>>x>>y;
        v.pb({x, y});
    }
    set<pair<ll, ll>> s(all(v));

    map<pair<ll, ll>, pair<ll, ll>> mp;
    queue<pair<ll, ll>> q;
    
    for(int i=0;i<n;i++) {
        ll x = v[i].fi, y = v[i].se;
        for(int j=0;j<4;j++) {
            ll xx = x+dx[j], yy = y+dy[j];
            if(!s.count({xx, yy})) {
                q.push({x, y});
                mp[{x, y}] = {xx, yy};
                break;
            }
        }
    }

    while(!q.empty()) {
        auto top = q.front();
        q.pop();
        ll x = top.fi, y = top.se;
        for(int i=0;i<4;i++) {
            ll xx = x+dx[i], yy = y+dy[i];
            if(s.count({xx, yy}) && !mp.count({xx, yy})) {
                mp[{xx, yy}] = mp[{x, y}];
                q.push({xx, yy});
            }
        }
    }

    for(auto [x, y]: v) {
        cout<<mp[{x,y}].fi<<" "<<mp[{x,y}].se<<nl;
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
