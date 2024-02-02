#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int dst;
  int weight;
};

vector<Node> v[10100];

int used[10100];
int n;
int maxi = -1, max_idx;

void dfs(int node, int len) {
  if (len > maxi) {
    maxi = len;
    max_idx = node;
  }
  for (auto next : v[node]) {
    if (used[next.dst] == 1)
      continue;
    used[next.dst] = 1;
    dfs(next.dst, len + next.weight);
    used[next.dst] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int from, to, val;
    cin >> from >> to >> val;
    v[from].push_back({to, val});
    v[to].push_back({from, val});
  }
  used[1] = 1;
  dfs(1, 0);

  for (int i = 0; i <= n; i++) {
    used[i] = 0;
  }

  used[max_idx] = 1;
  dfs(max_idx, 0);
  cout << maxi;
}