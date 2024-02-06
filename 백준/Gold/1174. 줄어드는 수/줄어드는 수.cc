#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n, used[10];
long long num[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
vector<long long> ans, v;

void dfs(int depth, int idx, int piv) {
  if (depth == piv) {
    long long sum = 0;
    for (auto c : v) {
      sum += c;
      sum *= 10;
    }
    sum /= 10;
    ans.push_back(sum);
    return;
  }

  for (int i = idx; i < 10; i++) {
    if (used[i])
      continue;
    used[i] = 1;
    v.push_back(num[i]);
    dfs(depth + 1, i + 1, piv);
    v.pop_back();
    used[i] = 0;
  }
}

int main() {
  cin >> n;

  for (int i = 1; i <= 10; i++)
    dfs(0, 0, i);

  sort(ans.begin(), ans.end());
  if (n > 1023 || n < 1)
    cout << "-1";
  else
    cout << ans[n - 1];

  return 0;
}