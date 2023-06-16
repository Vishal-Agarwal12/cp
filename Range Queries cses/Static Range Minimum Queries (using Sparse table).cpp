
// Time for building sparse table  = O(nlogn)
// time for processing each query = O(1)

#include <iostream>
#include <cmath>

using namespace std;
const int maxN = 2e5 + 1;
const int logN = 19;

int N, Q, a, b, l, k, x[maxN][logN];

int main()
{
    cin >> N >> Q;
    for (int i = 0; i < N; i++)
        cin >> x[i][0];

    for (int i = 1; i < logN; i++)
    {
        for (int j = 0; j <= N - (1 << i); j++)
        {
            x[j][i] = min(x[j][i - 1], x[j + (1 << (i - 1))][i - 1]);
        }
    }

    for (int q = 0; q < Q; q++)
    {
        cin >> a >> b;
        a--;
        b--;
        l = b - a + 1;
        k = log2(l);
        cout << min(x[a][k], x[b - (1 << k) + 1][k]) << endl;
    }

    return 0;
}
