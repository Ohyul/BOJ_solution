#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col, val;
};

queue<Node> q;

struct Map {
  int val;
  int up, down, right, left;
};

Map arr[51][51];
int visited[51][51];
int n, m, str_r, str_c, maxTime, cnt;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int cases, each;

void connect(int row, int col, int pipe) {
  if (pipe == 0) {
    arr[row][col].up = 0;
    arr[row][col].down = 0;
    arr[row][col].right = 0;
    arr[row][col].left = 0;
  } else if (pipe == 1) {
    arr[row][col].up = 1;
    arr[row][col].down = 1;
    arr[row][col].right = 1;
    arr[row][col].left = 1;
  } else if (pipe == 2) {
    arr[row][col].up = 1;
    arr[row][col].down = 1;
    arr[row][col].right = 0;
    arr[row][col].left = 0;
  } else if (pipe == 3) {
    arr[row][col].up = 0;
    arr[row][col].down = 0;
    arr[row][col].right = 1;
    arr[row][col].left = 1;
  } else if (pipe == 4) {
    arr[row][col].up = 1;
    arr[row][col].down = 0;
    arr[row][col].right = 1;
    arr[row][col].left = 0;
  } else if (pipe == 5) {
    arr[row][col].up = 0;
    arr[row][col].down = 1;
    arr[row][col].right = 1;
    arr[row][col].left = 0;
  } else if (pipe == 6) {
    arr[row][col].up = 0;
    arr[row][col].down = 1;
    arr[row][col].right = 0;
    arr[row][col].left = 1;
  } else if (pipe == 7) {
    arr[row][col].up = 1;
    arr[row][col].down = 0;
    arr[row][col].right = 0;
    arr[row][col].left = 1;
  }
}

int main() {
  cin >> cases;
  while (each++ < cases) {
    cin >> n >> m >> str_r >> str_c >> maxTime;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j].val;
        connect(i, j, arr[i][j].val);
      }
    }
    visited[str_r][str_c] = 1;
    cnt++;
    q.push({str_r, str_c, 1});
    while (!q.empty()) {
      Node curr = q.front();
      q.pop();
      int row = curr.row;
      int col = curr.col;
      int val = curr.val;
      if (val >= maxTime) continue;
      // upside
      if (row - 1 >= 0) {
        if (arr[row][col].up == 1 && arr[row - 1][col].down == 1 &&
            visited[row - 1][col] == 0) {
          visited[row - 1][col] = 1;
          cnt++;
          q.push({row - 1, col, val + 1});
        }
      }
      // downside
      if (row + 1 < n) {
        if (arr[row][col].down == 1 && arr[row + 1][col].up == 1 &&
            visited[row + 1][col] == 0) {
          visited[row + 1][col] = 1;
          cnt++;
          q.push({row + 1, col, val + 1});
        }
      }
      // leftside
      if (col - 1 >= 0) {
        if (arr[row][col].left == 1 && arr[row][col - 1].right == 1 &&
            visited[row][col - 1] == 0) {
          visited[row][col - 1] = 1;
          cnt++;
          q.push({row, col - 1, val + 1});
        }
      }
      // rightside
      if (col + 1 < m) {
        if (arr[row][col].right == 1 && arr[row][col + 1].left == 1 &&
            visited[row][col + 1] == 0) {
          visited[row][col + 1] = 1;
          cnt++;
          q.push({row, col + 1, val + 1});
        }
      }
    }
    cout << "#" << each << " " << cnt << "\n";
    cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        visited[i][j] = 0;
      }
    }
    while (!q.empty()) q.pop();
  }
}