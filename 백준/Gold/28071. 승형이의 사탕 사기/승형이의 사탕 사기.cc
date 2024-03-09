#include <iostream>
#include <vector>
using namespace std;

int n, m, k;
vector<int> dp(90001 + 1, 1e9);

int main() {
  cin >> n >> m >> k;

  dp[0] = 0;

  for (int coinIndex = 0; coinIndex < n; coinIndex++) {
    int val;
    cin >> val;

    for (int sum = val; sum <= 90001; sum++) {
      if (dp[sum - val] != 1e9) {
        dp[sum] = min(dp[sum], dp[sum - val] + 1);
      }
    }
  }

  for (int sum = 90001; sum >= 0; sum--) {
    if (sum % k == 0 && dp[sum] <= m) {
      cout << sum;
      return 0;
    }
  }
}