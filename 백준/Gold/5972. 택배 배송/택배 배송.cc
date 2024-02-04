#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to, val;
  bool operator<(const Edge &right) const {
    if (val < right.val)
      return false;
    if (val > right.val)
      return true;
    return false;
  }
};

vector<Edge> v[50500];
priority_queue<Edge> pq;
int n, m;
int dist[50500];

void dijkstra(int node) {
  dist[node] = 0;
  pq.push({node, 0});
  while (!pq.empty()) {
    Edge now = pq.top();
    pq.pop();
    for (Edge next : v[now.to]) {
      int nextVal = dist[now.to] + next.val;
      if (dist[next.to] <= nextVal)
        continue;
      dist[next.to] = nextVal;
      pq.push({next.to, nextVal});
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int from, to, val;
    cin >> from >> to >> val;
    v[from].push_back({to, val});
    v[to].push_back({from, val});
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
  }
  dijkstra(1);
  cout << dist[n];
}