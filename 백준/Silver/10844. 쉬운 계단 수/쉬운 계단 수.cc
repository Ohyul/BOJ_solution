#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9;
int n;
int result;

int main() {
    cin >> n;

    vector<vector<int>> dp(n + 1, vector<int>(10, 0));

    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 9; j++) {
            dp[i][j] = 0;
            if (j - 1 >= 0)
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            if (j + 1 <= 9)
                dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (int i = 0; i <= 9; i++)
        result = (result + dp[n][i]) % MOD;

    cout << result;
}
