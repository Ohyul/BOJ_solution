#include <iostream>
#include <limits>
#include <queue>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> adjacencyList;

struct Compare {
  bool operator()(pair<int, int> &a, pair<int, int> &b) {
    return a.first > b.first;
  }
};

void dijkstra(int vertices, int start) {
  vector<int> distances(vertices + 1, numeric_limits<int>::max());
  priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

  distances[start] = 0;
  minHeap.push({0, start});

  while (!minHeap.empty()) {
    int cost = minHeap.top().first;
    int currentNode = minHeap.top().second;
    minHeap.pop();

    if (cost > distances[currentNode])
      continue;

    for (const auto &edge : adjacencyList[currentNode]) {
      int neighborNode = edge.first;
      int edgeWeight = edge.second;

      if (distances[neighborNode] > cost + edgeWeight) {
        distances[neighborNode] = cost + edgeWeight;
        minHeap.push({distances[neighborNode], neighborNode});
      }
    }
  }

  for (int i = 1; i <= vertices; ++i) {
    if (distances[i] == numeric_limits<int>::max())
      cout << "INF";
    else
      cout << distances[i];
    cout << "\n";
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int vertices, edges, startNode;
  cin >> vertices >> edges >> startNode;

  adjacencyList.assign(vertices + 1, vector<pair<int, int>>());

  for (int i = 0; i < edges; ++i) {
    int from, to, weight;
    cin >> from >> to >> weight;
    adjacencyList[from].push_back({to, weight});
  }

  dijkstra(vertices, startNode);

  return 0;
}
