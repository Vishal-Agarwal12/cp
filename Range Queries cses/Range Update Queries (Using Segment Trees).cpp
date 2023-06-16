

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN = 2e5 + 5;
ll seg[MAXN * 3];
ll lazy[MAXN * 3];
int a[MAXN];

void push(int p, int l, int r)
{
    if (lazy[p])
    {
        seg[p] += lazy[p] * (r - l + 1);

        if (l != r)
        {
            lazy[p * 2] += lazy[p];
            lazy[p * 2 + 1] += lazy[p];
        }
        lazy[p] = 0;
    }
}

void build(int p, int l, int r)
{
    if (l == r)
    {
        seg[p] = a[r];
        return;
    }

    int mid = (l + r) >> 1;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

void update(int p, int l, int r, int a, int b, int val)
{
    push(p, l, r);

    if (l > b || r < a)
    {
        return;
    }

    if (l >= a && r <= b)
    {
        lazy[p] += val;
        push(p, l, r);
        return;
    }

    int mid = (l + r) / 2;
    update(p * 2, l, mid, a, b, val);
    update(p * 2 + 1, mid + 1, r, a, b, val);
    seg[p] = seg[p * 2] + seg[p * 2 + 1];
}

ll get(int p, int l, int r, int a, int b)
{
    push(p, l, r);

    if (l > b || r < a)
    {
        return 0;
    }

    if (l >= a && r <= b)
    {
        return seg[p];
    }

    int mid = (l + r) / 2;
    return get(p * 2, l, mid, a, b) + get(p * 2 + 1, mid + 1, r, a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    build(1, 1, n);

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int l, r, v;
            cin >> l >> r >> v;
            update(1, 1, n, l, r, v);
        }
        else
        {
            int b;
            cin >> b;
            cout << get(1, 1, n, b, b) << endl;
        }
    }
}
