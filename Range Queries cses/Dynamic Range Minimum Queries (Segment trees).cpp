

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, q;
vector<ll> seg;

void build(vector<int> &a, int i = 0, int l = 0, int r = (n - 1))
{
    if (l == r)
        seg[i] = a[l];
    else
    {
        int mid = (l + r) / 2;
        build(a, i * 2 + 1, l, mid);
        build(a, i * 2 + 2, mid + 1, r);
        seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
    }
}

void update(int id, int val, int l = 0, int r = n - 1, int i = 0)
{
    if (id > r || id < l)
        return;
    if (l == r)
    {
        if (l == id)
            seg[i] = val;
        return;
    }
    int mid = (l + r) / 2;
    update(id, val, l, mid, i * 2 + 1);
    update(id, val, mid + 1, r, i * 2 + 2);
    seg[i] = min(seg[i * 2 + 1], seg[i * 2 + 2]);
}

int getmin(int L, int R, int l = 0, int r = n - 1, int i = 0)
{
    if (l >= L && r <= R)
        return seg[i];
    if (l > R || r < L)
        return 1e9;
    int mid = (l + r) / 2;
    return min(getmin(L, R, l, mid, i * 2 + 1), getmin(L, R, mid + 1, r, i * 2 + 2));
}

void solve()
{
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    seg.resize(4 * n, 0);
    build(a);
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int id, val;
            cin >> id >> val;
            update(id - 1, val);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << getmin(l - 1, r - 1) << endl;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solve();
    return 0;
}
