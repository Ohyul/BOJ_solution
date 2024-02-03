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

vector<Edge> v[100100];
priority_queue<Edge> pq;
int n, max_idx, maxi = -1;
int dist[100100];

void dijkstra(int node) {
  dist[node] = 0;
  pq.push({node, 0});
  while (!pq.empty()) {
    Edge now = pq.top();
    if (now.weight > maxi) {
      maxi = now.weight;
      max_idx = now.to;
    }
    pq.pop();
    for (auto next : v[now.to]) {
      int nextWeight = next.weight + dist[now.to];
      if (dist[next.to] <= nextWeight)
        continue;
      dist[next.to] = nextWeight;
      pq.push({next.to, nextWeight});
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    dist[i + 1] = 1e9;
    int idx, to, weight;
    cin >> idx;
    while (true) {
      cin >> to;
      if (to == -1)
        break;
      cin >> weight;
      v[idx].push_back({to, weight});
    }
  }

  dijkstra(1);
  for (int i = 1; i <= n; i++) {
    dist[i] = 1e9;
  }
  maxi = -1;
  dijkstra(max_idx);
  cout << maxi;
}