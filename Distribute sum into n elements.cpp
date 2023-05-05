https://codeforces.com/contest/369/problem/B

#include <iostream>

using namespace std;

int main()
{
    int n, k, l, r, s_all, s_k;
    cin >> n >> k >> l >> r >> s_all >> s_k;
    int s = s_all - s_k;
    for (int i = n - k; i > 0; --i) {
        int x = s / i;
        cout << x << " ";
        s -= x;
    }
    s = s_k;
    for (int i = k; i > 0; --i) {
        int x = s / i;
        cout << x << " ";
        s -= x;
    }
    return 0;
}


