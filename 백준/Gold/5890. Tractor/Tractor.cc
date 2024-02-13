#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col, val;
  bool operator<(const Node &right) const { return val > right.val; }
};

priority_queue<Node> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int arr[1010][1010], dist[1010][1010];
int n, str_row, str_col, ans;

void dijkstra() {
  for (int i = 0; i < 1010; i++) {
    for (int j = 0; j < 1010; j++) {
      dist[i][j] = 1e9;
    }
  }
  dist[str_row][str_col] = 0;
  q.push({str_row, str_col, 0});
  while (!q.empty()) {
    Node now = q.top();
    q.pop();
    if (dist[now.row][now.col] < now.val)
      continue;
    for (int i = 0; i < 4; i++) {
      int nextR = now.row + dr[i];
      int nextC = now.col + dc[i];
      if (nextR < 0 || nextR >= 1001 || nextC < 0 || nextC >= 1001) {
        ans = now.val;
        return;
      }
      int nextVal = arr[nextR][nextC];
      if (dist[nextR][nextC] <= dist[now.row][now.col] + nextVal)
        continue;
      dist[nextR][nextC] = dist[now.row][now.col] + nextVal;
      q.push({nextR, nextC, dist[nextR][nextC]});
    }
  }
}

int main() {
  cin >> n >> str_row >> str_col;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    arr[r][c] = 1;
  }
  dijkstra();
  cout << ans;
}
