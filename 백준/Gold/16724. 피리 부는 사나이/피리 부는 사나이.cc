#include <iostream>
using namespace std;

int row, col, cnt;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int arr[1010][1010];
int used[1010][1010];

void dfs(int r, int c) {
  used[r][c] = 1;
  int nextR = r + dr[arr[r][c]], nextC = c + dc[arr[r][c]];
  if (used[nextR][nextC] == 1)
    cnt++;
  if (used[nextR][nextC] == 0)
    dfs(nextR, nextC);
  used[r][c] = 2;
}

int main() {
  cin >> row >> col;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      char input;
      cin >> input;
      if (input == 'D')
        arr[i][j] = 0;
      else if (input == 'U')
        arr[i][j] = 1;
      else if (input == 'R')
        arr[i][j] = 2;
      else if (input == 'L')
        arr[i][j] = 3;
    }
  }

  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (used[i][j] == 0) {
        dfs(i, j);
      }
    }
  }

  cout << cnt;
}