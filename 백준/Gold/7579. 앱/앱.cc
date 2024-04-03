#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct App {
    ll val, cost;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, sum = 0;
    cin >> n >> m;

    vector<App> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i].val;
    }
    for (int i = 0; i < n; i++) {
        cin >> arr[i].cost;
        sum += arr[i].cost;
    }

    vector<vector<ll>> dp(n, vector<ll>(sum + 1, 0));

    dp[0][arr[0].cost] = arr[0].val;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= sum; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - arr[i].cost >= 0) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - arr[i].cost] + arr[i].val);
            }
        }
    }

    ll minCost = -1;
    for (int j = 0; j <= sum; j++) {
        if (dp[n - 1][j] >= m) {
            minCost = j;
            break;
        }
    }

    cout << minCost;
}
