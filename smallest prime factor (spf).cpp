https://codeforces.com/contest/1766/problem/D

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

const int N = 10000000;
int spf[N+1];
void createSieve() {
	for(int i=1;i<=N;i++) {
		spf[i] = i;
	}
	
	for(int i=2;i*i<=N;i++) {
		if(spf[i] == i) {
			for(int j=i*i;j<=N;j+=i) {
				if(spf[j] == j) {
					spf[j] = i;
				}
			}
		}
	}
}

void solve()
{
    int x, y;
    cin>>x>>y;
    
    if(__gcd(x, y) > 1) {
    	cout<<0<<nl;
    	return;
    }
    if(y-x == 1) {
    	cout<<-1<<nl;
    	return;
    }
    
    y-=x;
    int ans = INT_MAX;
    while(y!=1) {
    	int p = spf[y];
    	// cout<<p<<nl;
    	ans = min(ans, (((x+p-1)/p)*p) - x);
    	y/=spf[y];
    }
    
    cout<<ans<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    createSieve();

    int T;
    cin>>T;
    while(T--)
        solve();

    return 0;
}
