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

bool isvalid(ll x, ll y) {
    if(x>=1 && y<=8 && x<=8 && y>=1) return true;
    else return false;
}

ll dx[] = {+1, -1, +2, -2, +1, -1, +2, -2};
ll dy[] = {+2, +2, +1, +1, -2, -2, -1, -1};

void solve()
{
    string s,t;
    cin>>s>>t;
    if(s==t) {
        cout<<0<<endl;
        return;
    }
    ll d1 = t[0]-'a'+1, d2 = t[1]-'0';
    queue<pair<ll, ll>> q;
    vector<vector<bool>> vis(9, vector<bool> (9, false));
    q.push({s[0]-'a'+1, s[1]-'0'});

    ll moves = 0;
    while(!q.empty()) {
        moves++;
        ll n = q.size();    
        for(int i=0;i<n;i++) {
            auto top = q.front();
            q.pop();
            for(int j=0;j<8;j++) {
                ll x = top.fi, y = top.se;
                ll xx = x+dx[j], yy = y+dy[j];
                if(xx == d1 && yy == d2) {
                    cout<<moves<<endl;
                    return;
                }
                if(isvalid(xx, yy) && !vis[xx][yy]) {
                    vis[xx][yy] = true;
                    q.push({xx, yy});
                }
            }
        }
    }
    cout<<moves<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
