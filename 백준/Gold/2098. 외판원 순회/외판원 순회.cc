#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int arr[16][16];
int dp[16][1 << 16];
int n;

int tsp(int now, int tar) {
  if (dp[now][tar] != 0)
    return dp[now][tar];

  if (tar == (1 << n) - 1) {
    if (arr[now][0] == 0)
      return 1e9;
    else
      return arr[now][0];
  }

  int val = 1e9;

  for (int i = 0; i < n; i++) {
    if ((tar & (1 << i)) != 0 || arr[now][i] == 0)
      continue;

    int ret = arr[now][i] + tsp(i, tar | (1 << i));

    if (ret < val)
      val = ret;
  }

  return dp[now][tar] = val;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  }

  cout << tsp(0, 1);
}