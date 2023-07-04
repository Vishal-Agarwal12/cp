https://codeforces.com/contest/1708/problem/B

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int findDivisibleByX(int l, int r, int x)
{
    if (l % x == 0)
    {
        return l;
    }

    int start = (l + x - 1) / x * x;
    if (start > r)
    {
        return -1;
    }

    return start;
}

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> v;

    for (int i = 1; i <= n; i++)
    {
        int result = findDivisibleByX(l, r, i);
        if (result != -1)
        {
            v.push_back(result);
        }
        else
        {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
    for (auto y : v)
        cout << y << " ";
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
