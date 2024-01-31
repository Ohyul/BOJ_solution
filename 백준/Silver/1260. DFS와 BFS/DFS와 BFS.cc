#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int> node[1010];
int dfs_used[1010];
int bfs_used[1010];
queue<int> q;

int n, m, v;

void dfs(int now) {
  cout << now << " ";
  for (int next : node[now]) {
    if (dfs_used[next] == 1)
      continue;
    dfs_used[next] = 1;
    dfs(next);
  }
}

int main() {
  cin >> n >> m >> v;
  for (int i = 0; i < m; i++) {
    int srt, dst;
    cin >> srt >> dst;
    node[srt].push_back(dst);
    node[dst].push_back(srt);
  }
  for (int i = 1; i <= n; i++) {
    sort(node[i].begin(), node[i].end());
  }
  dfs_used[v] = 1;
  dfs(v);
  cout << "\n";
  bfs_used[v] = 1;
  q.push(v);

  while (!q.empty()) {
    int now = q.front();
    cout << now << " ";
    q.pop();
    for (int next : node[now]) {
      if (bfs_used[next] == 1)
        continue;
      bfs_used[next] = 1;
      q.push(next);
    }
  }
}