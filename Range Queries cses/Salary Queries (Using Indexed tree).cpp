https://usaco.guide/problems/cses-1144-salary-queries/solution

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;
template <class T>
using Tree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int MOD = 1000000007;

int n, q, a[200001];
Tree<pii> o;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        o.insert({a[i], i});
    }
    for (int i = 0; i < q; i++)
    {
        char c;
        cin >> c;
        if (c == '!')
        {
            int x, y;
            cin >> x >> y;
            o.erase({a[x], x});
            a[x] = y;
            o.insert({a[x], x});
        }
        else
        {
            int x, y;
            cin >> x >> y;
            cout << o.order_of_key({y, MOD}) - o.order_of_key({x - 1, MOD}) << "\n";
        }
    }
}
