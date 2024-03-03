#include <iostream>
using namespace std;

int n, m;
bool arr[33][15];
int mini = 4;

bool run() {
  for (int col = 1; col <= m; col++) {
    int now = col;
    for (int row = 1; row <= n; row++) {
      if (arr[row][now])
        now++;
      else if (arr[row][now - 1])
        now--;
    }
    if (now != col) return false;
  }
  return true;
}

void install(int row, int col, int cnt) {
  if (cnt > 3 || cnt >= mini) return;
  if (run()) {
    mini = min(mini, cnt);
    return;
  }
  for (int i = row; i <= n; i++, col = 1) {
    for (int j = col; j < m; j++) {
      if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
      arr[i][j] = true;
      install(i, j + 2, cnt + 1);
      arr[i][j] = false;
    }
  }
}

int main() {
  int lines;
  cin >> m >> lines >> n;

  for (int i = 0; i < lines; i++) {
    int a, b;
    cin >> a >> b;
    arr[a][b] = true;
  }

  install(1, 0, 0);

  if (mini > 3)
    cout << -1;
  else
    cout << mini;

  return 0;
}