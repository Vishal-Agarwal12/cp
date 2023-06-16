
// Time complexity for building segment tree = O(n)
// Time for processing each query = O(logn)

#include <bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int, int>
#define ff first
#define ss second
using namespace std;

int seg[900000];
int v[900000];

void build(int l, int r, int idx = 1)
{
    if (l == r)
        seg[idx] = v[l];
    else
    {
        int mid = (l + r) / 2;
        build(l, mid, idx * 2);
        build(mid + 1, r, idx * 2 + 1);
        seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
    }
}

int query(int tL, int tR, int nL, int nR, int idx = 1)
{
    if (tL <= nL && nR <= tR)
        return seg[idx];
    else
    {
        int mid = (nL + nR) / 2, ans = 8e18;
        if (tL <= mid)
            ans = min(ans, query(tL, tR, nL, mid, idx * 2));
        if (tR > mid)
            ans = min(ans, query(tL, tR, mid + 1, nR, idx * 2 + 1));
        return ans;
    }
}

void update(int target, int val, int l, int r, int idx = 1)
{
    if (l == r)
        seg[idx] = val;
    else
    {
        int mid = (l + r) / 2;
        if (target <= mid)
            update(target, val, l, mid, idx * 2);
        if (target > mid)
            update(target, val, mid + 1, r, idx * 2 + 1);
        seg[idx] = min(seg[idx * 2], seg[idx * 2 + 1]);
    }
}

signed main()
{
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    build(1, n);
    for (int i = 0; i < q; i++)
    {
        int b, c;
        cin >> b >> c;
        cout << query(b, c, 1, n) << endl;
    }
}
