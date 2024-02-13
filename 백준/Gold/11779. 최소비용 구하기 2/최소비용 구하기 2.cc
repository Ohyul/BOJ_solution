#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to, val;
  bool operator<(const Edge &right) const { return val > right.val; }
};

priority_queue<Edge> q;
vector<Edge> lines[1010];
vector<int> path;
int dist[1010], pred[1010];
int n, m, str, dst, cnt;

void dijkstra() {
  for (int i = 0; i <= n; i++) {
    dist[i] = 1e9;
    pred[i] = -1;
  }
  dist[str] = 0;
  q.push({str, 0});
  while (!q.empty()) {
    Edge now = q.top();
    q.pop();
    for (Edge next : lines[now.to]) {
      int nextVal = dist[now.to] + next.val;
      if (dist[next.to] <= nextVal)
        continue;
      dist[next.to] = nextVal;
      pred[next.to] = now.to;
      q.push({next.to, nextVal});
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to, val;
    cin >> from >> to >> val;
    bool update = true;
    for (Edge &existingEdge : lines[from]) {
      if (existingEdge.to == to) {
        if (val < existingEdge.val) {
          existingEdge.val = val;
          update = false;
        }
        break;
      }
    }
    if (update) {
      lines[from].push_back({to, val});
    }
  }
  cin >> str >> dst;

  dijkstra();

  cout << dist[dst] << "\n";

  int node = dst;
  while (node != -1) {
    path.push_back(node);
    node = pred[node];
  }

  int cnt = path.size();
  cout << cnt << "\n";
  for (int i = path.size() - 1; i >= 0; --i) {
    cout << path[i] << " ";
  }
}