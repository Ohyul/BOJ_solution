#include <iostream>
#include <queue>

using namespace std;

struct maze {
  int row;
  int col;
  int dist;
};

string str;
int n, m, arr[100][100];
bool visited[100][100];

pair<int, int> p;
queue<maze> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> str;
    for (int j = 0; j < m; j++) {
      arr[i][j] = str[j] - '0';
    }
  }

  int min = 1e9;
  int row, col, dist;

  q.push({0, 0, 1});
  while (!q.empty()) {
    row = q.front().row;
    col = q.front().col;
    dist = q.front().dist;
    visited[row][col] = 1;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (row + dr[i] >= 0 && row + dr[i] < n && col + dc[i] >= 0 &&
          col + dc[i] < m && visited[row + dr[i]][col + dc[i]] == 0 &&
          arr[row + dr[i]][col + dc[i]] == 1) {
        visited[row + dr[i]][col + dc[i]] = 1;
        q.push({row + dr[i], col + dc[i], dist + 1});
      }
    }
    if (row == n - 1 && col == m - 1) {
      if (min >= dist && dist != 0) {
        min = dist;
      }
    }
  }
  cout << min;
}