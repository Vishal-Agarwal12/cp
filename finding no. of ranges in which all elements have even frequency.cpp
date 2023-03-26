#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
int cnt[1 << 10];
 
int main() {
    ios::sync_with_stdio(0);
 
    string s; cin >> s;
    
    int t = 0;
    ll ans = 0;
    cnt[0] = 1;
    
    for(auto c : s) {
        int x = c - '0';
        t ^= (1 << x);
        
        ans += cnt[t];
        cnt[t] ++;
    }
    cout << ans << '\n';
}
