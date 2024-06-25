#include <iostream>
typedef long long ll;
using namespace std;

int n;
ll dp[1010][10];
ll sum;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < 10; i++) dp[0][i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = 0;
            for (int k = j; k < 10; k++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][k]) % 10007;
            }
        }
    }

    for (int i = 0; i < 10; i++) sum = (sum + dp[n - 1][i]) % 10007;

    cout << sum;
}