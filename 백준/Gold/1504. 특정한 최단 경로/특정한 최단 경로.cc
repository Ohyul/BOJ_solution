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

priority_queue<Edge> pq;
vector<Edge> v[808];
int dist[808];
int n, e, node1, node2;

int ston1, ston2, n1ton2;
int n1tod, n2tod;

void dijkstra(int node) {
  dist[node] = 0;
  pq.push({node, 0});
  while (!pq.empty()) {
    Edge now = pq.top();
    pq.pop();
    for (Edge next : v[now.to]) {
      int nextVal = next.val + dist[now.to];
      if (dist[next.to] <= nextVal)
        continue;
      dist[next.to] = nextVal;
      pq.push({next.to, nextVal});
    }
  }
}

int main() {
  cin >> n >> e;
  for (int i = 0; i < e; i++) {
    int from, to, val;
    cin >> from >> to >> val;
    v[from].push_back({to, val});
    v[to].push_back({from, val});
  }
  cin >> node1 >> node2;
  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
  }
  dijkstra(node1);
  ston1 = dist[1];
  n1tod = dist[n];
  n1ton2 = dist[node2];

  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
  }
  dijkstra(node2);
  ston2 = dist[1];
  n2tod = dist[n];

  int total_dist = min(ston1 + n1ton2 + n2tod, ston2 + n1ton2 + n1tod);

  if (total_dist >= 1e9 || total_dist < 0)
    cout << "-1";
  else
    cout << total_dist;
}