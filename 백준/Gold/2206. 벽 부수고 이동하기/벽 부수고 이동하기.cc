#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col, val, broke;
};

queue<Node> q;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int arr[1010][1010], f_used[1010][1010], s_used[1010][1010], dist[1010][1010];
int n, m, mini = 1e9;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string in;
    cin >> in;
    for (int j = 0; j < m; j++) {
      arr[i][j] = in[j] - '0';
      dist[i][j] = 1e9;
    }
  }
  dist[0][0] = 1;
  f_used[0][0] = 1;
  q.push({0, 0, 1, 0});
  while (!q.empty()) {
    Node now = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextR = now.row + dr[i];
      int nextC = now.col + dc[i];
      int nextVal = now.val + 1;
      int nextBr = (arr[nextR][nextC] == 1) ? now.broke + 1 : now.broke;
      if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m)
        continue;
      if (nextBr > 1)
        continue;
      if (nextBr == 0) {
        if (f_used[nextR][nextC] == 1)
          continue;
        f_used[nextR][nextC] = 1;
        dist[nextR][nextC] = min(dist[nextR][nextC], nextVal);
        q.push({nextR, nextC, nextVal, nextBr});
      } else if (nextBr == 1) {
        if (s_used[nextR][nextC] == 1)
          continue;
        s_used[nextR][nextC] = 1;
        dist[nextR][nextC] = min(dist[nextR][nextC], nextVal);
        q.push({nextR, nextC, nextVal, nextBr});
      }
    }
  }
  if (dist[n - 1][m - 1] == 1e9)
    cout << "-1";
  else
    cout << dist[n - 1][m - 1];
}