#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col, val;
};
queue<Node> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int m, cnt, white, mini = 1e9;

char arr[2][55];
int used[2][55];
int dist[2][55];

void bfs() {
  while (!q.empty()) {
    Node now = q.front();
    dist[now.row][now.col] = now.val;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextR = now.row + dr[i];
      int nextC = now.col + dc[i];
      if (nextR < 0 || nextR >= 2 || nextC < 0 || nextC >= m ||
          arr[nextR][nextC] == '#')
        continue;
      if (used[nextR][nextC] == 1)
        continue;
      used[nextR][nextC] = 1;
      q.push({nextR, nextC, now.val + 1});
    }
  }
}

int main() {
  cin >> m;
  for (int i = 0; i < 2; i++) {
    string in;
    cin >> in;
    for (int j = 0; j < m; j++) {
      arr[i][j] = in[j];
      dist[i][j] = 1e9;
      if (arr[i][j] == '.')
        white++;
    }
  }
  if (arr[0][0] == '.') {
    used[0][0] = 1;
    q.push({0, 0, 0});
  }
  if (arr[1][0] == '.') {
    used[1][0] = 1;
    q.push({1, 0, 0});
  }
  bfs();

  mini = min(dist[0][m - 1], dist[1][m - 1]);

  cout << white - mini - 1;
}