#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

char arr[7][7];
int connection[7][7], mini = 13;
const int dr[4] = {1, -1, 0, 0}, dc[] = {0, 0, 1, -1};
int bits = 1 << 26;
map<int, int> used;
vector<pair<int, int>> start_points;

int connected(int row, int col) {
  connection[row][col] = 1;
  int cnt = 1;
  for (int i = 0; i < 4; i++) {
    int nextR = row + dr[i];
    int nectC = col + dc[i];
    if (arr[nextR][nectC] != '*' || nextR > 5 || nectC > 5 || nextR < 1 ||
        nectC < 1 || connection[nextR][nectC] != 0) {
      continue;
    }
    cnt += connected(nextR, nectC);
  }
  return cnt;
}

void update(int nowCount, int bit) {
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 5; j++) {
      connection[i][j] = 0;
    }
  }
  if (connected(start_points[0].first, start_points[0].second) ==
      start_points.size()) {
    mini = nowCount;
    return;
  }
  if (nowCount >= mini) {
    return;
  }
  for (int i = 0; i < start_points.size(); i++) {
    int row = start_points[i].first;
    int col = start_points[i].second;
    for (int j = 0; j < 4; j++) {
      int nextR = row + dr[j];
      int nectC = col + dc[j];
      if (nextR < 1 || nectC < 1 || nextR > 5 || nectC > 5 ||
          arr[nextR][nectC] == '*') {
        continue;
      }
      int newPosition = bit | (1 << ((5 * (nextR - 1)) + nectC));
      newPosition = newPosition & ~(1 << (5 * (row - 1) + col));
      if (used.count(newPosition) != 0 && used[newPosition] <= nowCount + 1) {
        continue;
      }
      used[newPosition] = nowCount + 1;
      start_points[i] = {nextR, nectC};
      arr[nextR][nectC] = '*';
      arr[row][col] = '.';
      update(nowCount + 1, newPosition);
      arr[nextR][nectC] = '.';
      arr[row][col] = '*';
      start_points[i] = {row, col};
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  for (int i = 1; i <= 5; i++) {
    string input;
    cin >> input;
    for (int j = 1; j <= 5; j++) {
      arr[i][j] = input[j - 1];
      if (arr[i][j] == '*') {
        start_points.push_back({i, j});
        bits |= (1 << ((5 * (i - 1)) + j));
      }
    }
  }

  used[bits] = 0;
  update(0, bits);
  cout << mini << "\n";

  return 0;
}