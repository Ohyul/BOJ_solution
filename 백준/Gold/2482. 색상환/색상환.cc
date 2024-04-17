#include <iostream>
#include <climits>
using namespace std;

int n, k;
int dp[1010][1010];
int ans;

int main() {
	cin >> n >> k;


    for (int i = 0; i < 1002; i++) {
        dp[i][0] = 1;  
        dp[i][1] = i;  
    }

    for (int i = 2; i < n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i - 2][j - 1] + dp[i - 1][j]) % int(1e9 + 3);
        }
    }

    ans = ((dp[n - 3][k - 1] + dp[n - 1][k]) % int(1e9 + 3));
    cout << ans;
}