#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Edge {
  int to, weight;
  bool operator<(const Edge &right) const {
    if (weight < right.weight)
      return false;
    if (weight > right.weight)
      return true;
    return false;
  }
};

priority_queue<Edge> pq;
vector<Edge> v[1010];
int dist[1010], tox[1010], fromx[1010];
int n, m, x, maxi = -1;

void dijkstra(int node) {
  dist[node] = 0;
  pq.push({node, 0});
  while (!pq.empty()) {
    Edge now = pq.top();
    pq.top();
    pq.pop();
    for (auto next : v[now.to]) {
      int nextWeight = dist[now.to] + next.weight;
      if (dist[next.to] <= nextWeight)
        continue;
      pq.push({next.to, nextWeight});
      dist[next.to] = nextWeight;
    }
  }
}

int main() {
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    int from, to, weight;
    cin >> from >> to >> weight;
    v[from].push_back({to, weight});
  }
  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
  }
  dijkstra(x);
  for (int i = 1; i <= n; i++) {
    fromx[i] = dist[i];
    dist[i] = 1e9;
  }
  for (int i = 1; i <= n; i++) {
    if (i == x)
      continue;
    dijkstra(i);
    tox[i] = dist[x];
    for (int j = 1; j <= n; j++) {
      dist[j] = 1e9;
    }
  }
  for (int i = 1; i <= n; i++) {
    maxi = max(maxi, tox[i] + fromx[i]);
  }
  cout << maxi;
}