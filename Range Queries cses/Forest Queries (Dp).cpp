

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1001;

char c;
int N, Q, a[maxN][maxN];

int main()
{
    cin >> N >> Q;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> c;
            a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
            if (c == '*')
                a[i][j]++;
        }
    }
    for (int q = 0; q < Q; q++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1] << endl;
    }
}
