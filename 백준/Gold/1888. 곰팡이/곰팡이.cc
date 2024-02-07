#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col;
};
queue<Node> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int arr[110][110];
int used[110][110];
int n, m, cnt, day;

void updateArray(int row_st, int col_st, int size, int value) {
  for (int r = 0; r < 2 * size + 1; r++) {
    for (int c = 0; c < 2 * size + 1; c++) {
      if (row_st + r < 0 || row_st + r >= n || col_st + c < 0 ||
          col_st + c >= m)
        continue;
      if (arr[row_st + r][col_st + c] < value) {
        used[row_st + r][col_st + c] = 0;
        arr[row_st + r][col_st + c] = value;
      }
    }
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string in;
    cin >> in;
    for (int j = 0; j < m; j++) {
      arr[i][j] = in[j] - '0';
    }
  }
  while (true) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (arr[i][j] > 0 && used[i][j] == 0) {
          cnt++;
          used[i][j] = 1;
          q.push({i, j});
          while (!q.empty()) {
            Node now = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
              int nextR = now.row + dr[k];
              int nextC = now.col + dc[k];
              if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m)
                continue;
              if (used[nextR][nextC] == 1 || arr[nextR][nextC] == 0)
                continue;
              used[nextR][nextC] = 1;
              q.push({nextR, nextC});
            }
          }
        }
      }
    }

    if (cnt == 1) {
      break;
    } else {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (arr[i][j] > 0 && used[i][j] == 1) {
            int row_st = i - arr[i][j];
            int col_st = j - arr[i][j];
            updateArray(row_st, col_st, arr[i][j], arr[i][j]);
          }
          used[i][j] = 0;
        }
      }
    }

    day++;
  }
  cout << day;
}