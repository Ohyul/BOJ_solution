#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Node {
  int row, col, val, dir;
};

int arr[105][105];
vector<Node> v[5];
int n, maxi;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int tcs, tc;

void run(int row, int col, int dir) {
  int str_row = row;
  int str_col = col;
  int cnt = 0;
  row += dr[dir];
  col += dc[dir];
  while (true) {
    if (row == str_row && col == str_col) break;
    if (arr[row][col] == -1) break;
    if (arr[row][col] == 5 || row < 0 || row >= n || col < 0 || col >= n) {
      cnt++;
      if (dir == 0)
        dir = 1;
      else if (dir == 1)
        dir = 0;
      else if (dir == 2)
        dir = 3;
      else if (dir == 3)
        dir = 2;
    } else if (arr[row][col] == 1) {
      cnt++;
      if (dir == 0)
        dir = 2;
      else if (dir == 1)
        dir = 0;
      else if (dir == 2)
        dir = 3;
      else if (dir == 3)
        dir = 1;
    } else if (arr[row][col] == 2) {
      cnt++;
      if (dir == 0)
        dir = 1;
      else if (dir == 1)
        dir = 2;
      else if (dir == 2)
        dir = 3;
      else if (dir == 3)
        dir = 0;
    } else if (arr[row][col] == 3) {
      cnt++;
      if (dir == 0)
        dir = 1;
      else if (dir == 1)
        dir = 3;
      else if (dir == 2)
        dir = 0;
      else if (dir == 3)
        dir = 2;
    } else if (arr[row][col] == 4) {
      cnt++;
      if (dir == 0)
        dir = 3;
      else if (dir == 1)
        dir = 0;
      else if (dir == 2)
        dir = 1;
      else if (dir == 3)
        dir = 2;
    } else if (arr[row][col] >= 6 && arr[row][col] <= 10) {
      int index = arr[row][col] - 6;
      if (!v[index].empty()) {
        if (v[index][0].row == row && v[index][0].col == col) {
          row = v[index][1].row;
          col = v[index][1].col;
        } else {
          row = v[index][0].row;
          col = v[index][0].col;
        }
      }
    }
    row += dr[dir];
    col += dc[dir];
  }
  maxi = max(maxi, cnt);
}

int main() {
  cin >> tcs;
  while (tc++ < tcs) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
        if (arr[i][j] >= 6 && arr[i][j] <= 10) {
          v[arr[i][j] - 6].push_back({i, j});
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (arr[i][j] == 0) {
          for (int k = 0; k < 4; k++) {
            run(i, j, k);
          }
        }
      }
    }
    cout << "#" << tc << " " << maxi << "\n";
    for (int i = 0; i < 5; i++) {
      v[i].clear();
      maxi = 0;
    }
  }
}