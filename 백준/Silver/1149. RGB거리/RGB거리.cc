#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1000][3];
int dp[1000][3];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 0; i < 3; i++) {
        dp[0][i] = arr[0][i];
    }

    dp[1][0] = min(dp[0][1] + arr[1][0], dp[0][2] + arr[1][0]);
    dp[1][1] = min(dp[0][0] + arr[1][1], dp[0][2] + arr[1][1]);
    dp[1][2] = min(dp[0][0] + arr[1][2], dp[0][1] + arr[1][2]);

    for (int i = 2; i < n; i++) {
        dp[i][0] = min(dp[i - 1][1] + arr[i][0], dp[i - 1][2] + arr[i][0]);
        dp[i][1] = min(dp[i - 1][0] + arr[i][1], dp[i - 1][2] + arr[i][1]);
        dp[i][2] = min(dp[i - 1][0] + arr[i][2], dp[i - 1][1] + arr[i][2]);
    }

    int min_ = min(min(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);
    cout << min_;
    return 0;
}