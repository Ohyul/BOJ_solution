#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int to, val;
};

const int MAX_NODES = 10001;
vector<Edge> graph[MAX_NODES];
int used[MAX_NODES];
int maxAnswer, edgeCnt, currentCost;

int from, to, val;

void dfs(int current, int cost) {
  currentCost = max(currentCost, cost);
  used[current] = 1;
  for (auto neighbor : graph[current]) {
    if (!used[neighbor.to]) {
      dfs(neighbor.to, cost + neighbor.val);
    }
  }
}

int main() {

  while (cin >> from >> to >> val) {
    graph[from].push_back({to, val});
    graph[to].push_back({from, val});
    edgeCnt++;
  }

  for (int i = 1; i <= edgeCnt + 1; i++) {
    memset(used, 0, sizeof(used));
    currentCost = 0;
    dfs(i, 0);
    maxAnswer = max(maxAnswer, currentCost);
  }

  cout << maxAnswer;

  return 0;
}