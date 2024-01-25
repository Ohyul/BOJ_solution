#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MOD = 9901;
long long dp[100000];
long n;

int main() {
    cin >> n;

    dp[0] = 3 % MOD;
    dp[1] = 7 % MOD;

    for (long long i = 2; i < n; i++) {
        dp[i] = (2 * dp[i - 1] + dp[i - 2]) % MOD;
    }

    cout << dp[n - 1] << endl;

    return 0;
}
