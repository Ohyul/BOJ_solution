#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int T;
int day, month1, month3, year;
vector<int> month(13);

int main() {
  cin >> T;

  for (int tc = 1; tc <= T; ++tc) {
    cin >> day >> month1 >> month3 >> year;

    for (int i = 1; i <= 12; ++i) {
      cin >> month[i];
    }

    vector<int> dp(13, 0);

    for (int i = 1; i <= 12; ++i) {
      int mini = dp[i - 1] + month[i] * day;
      mini = min(mini, dp[i - 1] + month1);

      if (i >= 3) {
        mini = min(mini, dp[i - 3] + month3);
      }

      if (i >= 12) {
        mini = min(mini, dp[i - 12] + year);
      }
      dp[i] = mini;
    }

    cout << "#" << tc << " " << dp[12] << "\n";
  }
}
