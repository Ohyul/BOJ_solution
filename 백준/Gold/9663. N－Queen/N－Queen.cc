#include <algorithm>
#include <iostream>
using namespace std;

int used[17][17];
int n, cnt;

bool check(int row, int col) {
  for (int i = 0; i < row; i++) {
    if (used[i][col])
      return false;
  }
  for (int i = 0; i <= row; i++) { 
    if (row - i < 0 || col - i < 0)
      break;
    if (used[row - i][col - i])
      return false;
  }
  for (int i = 1; i <= row; i++) { 
    if (row - i < 0 || col + i >= n)
      break;
    if (used[row - i][col + i])
      return false;
  }
  return true;
}

void dfs(int row) {
  if (row == n) {
    cnt++;
    return;
  }
  for (int col = 0; col < n; col++) {
    if (!check(row, col))
      continue;
    used[row][col] = 1;
    dfs(row + 1);
    used[row][col] = 0;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  dfs(0); 
  cout << cnt;
}