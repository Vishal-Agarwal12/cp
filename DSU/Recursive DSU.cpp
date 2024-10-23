#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#include "debug.h"
#endif

using ll = long long;
using maxheap = priority_queue<ll>;                           // maxheap
using minheap = priority_queue<ll, vector<ll>, greater<ll>>;  // minheap
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define pb push_back
#define eb emplace_back
#define fi first
#define nl endl
#define se second
const ll Mod = 998244353;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

auto find_sets(ll v, vector<ll> &p) {
  if (v == p[v]) return v;
  return p[v] = find_sets(p[v], p);
}

auto union_sets(ll x, ll y, vector<ll> &p) {
  ll a = find_sets(x, p);
  ll b = find_sets(y, p);
  if (a != b) {
    p[b] = a;
  }
}

void solve() {
  ll n, m1, m2;
  cin >> n >> m1 >> m2;

  vector<ll> p1(n + 1), p2(n + 1);
  for (int i = 1; i <= n; i++) {
    p1[i] = i;
    p2[i] = i;
  }

  for (int i = 0; i < m1; i++) {
    ll u, v;
    cin >> u >> v;

    union_sets(u, v, p1);
  }

  for (int i = 0; i < m2; i++) {
    ll u, v;
    cin >> u >> v;

    union_sets(u, v, p2);
  }

  vector<pair<ll, ll>> v;
  for (ll i = 1; i < n; i++) {
    for (ll j = i + 1; j <= n; j++) {
      if (find_sets(i, p1) != find_sets(j, p1) &&
          find_sets(i, p2) != find_sets(j, p2)) {
        union_sets(i, j, p1);
        union_sets(i, j, p2);
        v.pb({i, j});
      }
    }
  }

  cout << v.size() << nl;
  for (auto x : v) {
    cout << x.fi << " " << x.se << nl;
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  // freopen("input.txt", "rt", stdin);
  // freopen("output.txt", "wt", stdout);

  solve();

  return 0;
}
