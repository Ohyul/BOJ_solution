#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int tc;
int dp[510][510];
int arr[510];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    while (tc--) {
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            arr[i] = arr[i - 1] + a;
        }

        for (int i = 1; i < k; i++) {
            for (int x = 1; x <= k - i; x++) {
                int y = x + i;
                dp[x][y] = INT_MAX;

                for (int mid = x; mid < y; mid++) {
                    dp[x][y] = min(dp[x][y], dp[x][mid] + dp[mid + 1][y] + arr[y] - arr[x - 1]);
                }
            }
        }
        cout << dp[1][k] << "\n";
    }
}
