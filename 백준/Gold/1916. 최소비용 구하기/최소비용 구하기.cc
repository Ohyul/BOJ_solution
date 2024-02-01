#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9;

struct Node {
  int dst, weight;
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m, srt, dst;
  cin >> n >> m;

  vector<vector<Node>> graph(n + 1);
  vector<int> dist(n + 1, INF);

  for (int i = 0; i < m; i++) {
    int row, col, weight;
    cin >> row >> col >> weight;
    graph[row].push_back({col, weight});
  }

  cin >> srt >> dst;

  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      pq;
  dist[srt] = 0;
  pq.push({0, srt});

  while (!pq.empty()) {
    int u = pq.top().second;
    int cost = pq.top().first;
    pq.pop();

    if (cost > dist[u])
      continue;

    for (const auto &neighbor : graph[u]) {
      int v = neighbor.dst;
      int weight = neighbor.weight;

      if (dist[u] + weight < dist[v]) {
        dist[v] = dist[u] + weight;
        pq.push({dist[v], v});
      }
    }
  }

  cout << dist[dst];
  return 0;
}