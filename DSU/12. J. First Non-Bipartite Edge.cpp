#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define pb push_back
#define eb emplace_back
#define fi first
#define nl '\n'
#define se second

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<pair<int, int>> edg;
    int root = -1;
    for(int i=0;i<m;i++) {
        int u, v;
        cin>>u>>v;
        edg.pb({u, v});
        if(i == 0) root = u;
    }

    auto bfs = [&](int mid) -> bool {
        vector<vector<int>> ad(n+1);
        vector<int> col(n+1);
        for(int i=1;i<=n;i++) col[i] = -1;
        for(int i=0;i<mid;i++) {
            ad[edg[i].fi].pb(edg[i].se);
            ad[edg[i].se].pb(edg[i].fi);
        }
        queue<int> q;
        q.push(root);
        col[root] = 0;
        while(!q.empty()) {
            int ss = q.size();
            for(int i=0;i<ss;i++) {
                int top = q.front();
                q.pop();
                
                for(auto it: ad[top]) {
                    if(col[it] == -1) {
                        col[it] = 1^col[top];
                        q.push(it);
                    } 
                    else if(col[it] == col[top]) {
                        return false;
                    }
                }
            } 
        }
        return true;
    };

    int l = 1, r = m, ans = -1;
    while(l<=r) {
        int mid = (l+r)/2;
        if(bfs(mid)) {
            l = mid+1;
        }
        else {
            ans = mid;
            r = mid-1;
        }
    }
    cout<<ans<<nl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //freopen("input.txt", "rt", stdin);
    //freopen("output.txt", "wt", stdout);

    solve();

    return 0;
}
