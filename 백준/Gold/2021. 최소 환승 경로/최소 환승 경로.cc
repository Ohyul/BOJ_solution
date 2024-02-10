#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<int> v[200200];

int dist[200200];
int n, m, k;
int srt, dst;

void dijkstra(int now) {
  for (int i = 0; i < 200200; i++)
    dist[i] = 1e9;
  priority_queue<pair<int, int>> pq;

  dist[now] = 0;
  pq.push({0, now});

  while (!pq.empty()) {
    int now = pq.top().second;
    int dis = -pq.top().first;
    pq.pop();

    for (auto next : v[now]) {
      if (next > n) {
        if (dist[next] > dis + 1) {
          dist[next] = dis + 1;
          pq.push({-dist[next], next});
        }
      } else {
        if (dist[next] > dis) {
          dist[next] = dis;
          pq.push({-dist[next], next});
        }
      }
    }
  }
  return;
}

int main() {

  cin >> n >> m;
  for (int i = n + 1; i <= n + m; i++) {
    while (1) {
      cin >> k;
      if (k == -1)
        break;

      v[k].push_back(i);
      v[i].push_back(k);
    }
  }
  cin >> srt >> dst;

  if (srt == dst) {
    cout << 0;
    return 0;
  }

  dijkstra(srt);

  if (dist[dst] == 1e9)
    cout << -1;
  else
    cout << dist[dst] - 1;

  return 0;
}