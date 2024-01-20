#include <iostream>
#include <queue>

struct str {
  int row;
  int col;
  int dist;
};

using namespace std;

int n, m, arr[1000][1000], ans[1000][1000];
bool visited[1000][1000];
pair<int, int> p;
queue<str> q;
int dest_row, dest_col;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) {
        dest_row = i;
        dest_col = j;
      }
      if (arr[i][j] == 0) {
        ans[i][j] = 0;
      }
    }
  }

  visited[dest_row][dest_col] = 1;
  ans[dest_row][dest_col] = 0;
  q.push({dest_row, dest_col, 0});
  while (!q.empty()) {
    int row = q.front().row;
    int col = q.front().col;
    int dist = q.front().dist;
    ans[row][col] = dist;
    q.pop();
    for (int i = 0; i < 4; i++) {
      if (row + dr[i] >= 0 && row + dr[i] < n &&
          col + dc[i] >= 0 && col + dc[i] < m &&
          visited[row + dr[i]][col + dc[i]] == 0 &&
          arr[row + dr[i]][col + dc[i]] == 1) {
        visited[row + dr[i]][col + dc[i]] = 1;
        q.push({row + dr[i], col + dc[i], dist + 1});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (i == dest_row && j == dest_col) {
        cout << "0"
             << " ";
      } else if (ans[i][j] == 0 && arr[i][j] != 0) {
        cout << "-1"
             << " ";
      } else {
        cout << ans[i][j] << " ";
      }
    }
    cout << endl;
  }
}
