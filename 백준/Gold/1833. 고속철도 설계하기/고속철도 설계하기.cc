#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Edge {
  int to, weight;
};

void prim(vector<vector<int>> &map, int n, int result) {
  vector<int> distance(n, 10010);
  vector<int> prevIndex(n, 0);
  distance[0] = 0;
  vector<bool> visited(n, false);

  int cnt = 0;
  vector<pair<int, int>> edges;

  for (int i = 0; i < n; i++) {
    int minIndex = -1;

    for (int j = 0; j < n; j++) {
      if (!visited[j] && (minIndex == -1 || distance[j] < distance[minIndex])) {
        minIndex = j;
      }
    }

    visited[minIndex] = true;
    result += abs(distance[minIndex]);

    if (i != 0 && distance[minIndex] > 0) {
      cnt++;
      edges.emplace_back(prevIndex[minIndex] + 1, minIndex + 1);
    }

    for (int j = 0; j < n; j++) {
      if (!visited[j] && map[minIndex][j] < distance[j]) {
        distance[j] = map[minIndex][j];
        prevIndex[j] = minIndex;
      }
    }
  }

  cout << result << " " << cnt << '\n';

  for (const auto &edge : edges) {
    cout << edge.first << " " << edge.second << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> map(n, vector<int>(n, 0));
  int result = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      if (map[i][j] < 0) {
        result -= map[i][j];
        map[i][j] = 0;
      }
    }
  }

  result /= 2;
  prim(map, n, result);

  return 0;
}