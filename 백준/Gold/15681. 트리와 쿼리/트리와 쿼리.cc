#include <iostream>
#include <vector>
using namespace std;

const int maxN = 100010;

int n, r, q;
vector<int> tree[maxN], ans;
int dp[maxN];

int find(int node) {
  dp[node] = 1;

  for (int i = 0; i < tree[node].size(); ++i) {
    int next = tree[node][i];
    if (dp[next] == -1) {
      dp[node] += find(next);
    }
  }

  return dp[node];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> r >> q;

  for (int i = 1; i <= n; ++i) {
    dp[i] = -1;
  }

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  find(r);

  for (int i = 0; i < q; ++i) {
    int u;
    cin >> u;
    ans.push_back(dp[u]);
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}