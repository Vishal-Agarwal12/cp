#include <iostream>

using namespace std;

const int MOD = 1000000007;

long long powerMod(long long a, long long b) {
    long long result = 1;
    while (b > 0) {
        if (b % 2 == 1)
            result = (result * a) % MOD;
        a = (a * a) % MOD;
        b /= 2;
    }
    return result;
}

int main() {
    long long a, b;
    cout << "Enter the base (a): ";
    cin >> a;
    cout << "Enter the exponent (b): ";
    cin >> b;

    long long result = powerMod(a, b);
    cout << "Result: " << result << endl;

    return 0;
}
