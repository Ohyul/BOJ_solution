#include <iostream>
#include <queue>
using namespace std;

struct tomato {
  int time;
  int row;
  int col;
};

queue<tomato> q;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int n, m;
int arr[1010][1010];
int used[1010][1010];

int main() {
  cin >> n >> m;
  int changeFlag = 0;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) {
        used[i][j] = 1;
        q.push({1, i, j});
      } else if (arr[i][j] == 0) {
        changeFlag = 1;
      }
    }
  }
  if (changeFlag == 0) {
    cout << "0";
    return 0;
  }
  while (!q.empty()) {
    int nowTime = q.front().time;
    int nowRow = q.front().row;
    int nowCol = q.front().col;
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nextRow = nowRow + dr[i];
      int nextCol = nowCol + dc[i];
      if (arr[nextRow][nextCol] == -1 || used[nextRow][nextCol] == 1)
        continue;
      if (nextRow < 0 || nextRow >= m || nextCol < 0 || nextCol >= n)
        continue;
      arr[nextRow][nextCol] = nowTime;
      used[nextRow][nextCol] = 1;
      q.push({nowTime + 1, nextRow, nextCol});
    }
  }

  int maxi = -1;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[i][j] == 0) {
        cout << -1;
        return 0;
      } else if (arr[i][j] > 0 && arr[i][j] > maxi) {
        maxi = arr[i][j];
      }
    }
  }
  cout << maxi;
  return 0;
}