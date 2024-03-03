#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Core {
  int row, col;
};

vector<Core> Cores;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
int num, maxi, minDist;
int arr[15][15];

void dfs(int idx, int dist, int conn) {
  if (idx == Cores.size()) {
    if (conn > maxi || (conn == maxi && dist < minDist)) {
      minDist = dist;
      maxi = conn;
    }
    return;
  }

  for (int i = 0; i < 4; i++) {
    int nowR = Cores[idx].row;
    int nowC = Cores[idx].col;
    int cnt = 0;

    while (true) {
      nowC += dc[i];
      nowR += dr[i];
      cnt++;

      if (arr[nowR][nowC] == 1 || arr[nowR][nowC] == 2) {
        cnt = 0;
        break;
      }

      if (arr[nowR][nowC] == 0 &&
          (nowC == 0 || nowR == 0 || nowC == num - 1 || nowR == num - 1)) {
        break;
      }
    }

    if (cnt > 0) {
      nowR = Cores[idx].row;
      nowC = Cores[idx].col;

      while (true) {
        nowC += dc[i];
        nowR += dr[i];

        if (nowC < 0 || nowR < 0 || nowC > num - 1 || nowR > num - 1) break;

        arr[nowR][nowC] = 2;
      }

      dfs(idx + 1, dist + cnt, conn + 1);

      nowR = Cores[idx].row;
      nowC = Cores[idx].col;

      while (true) {
        nowC += dc[i];
        nowR += dr[i];

        if (nowC < 0 || nowR < 0 || nowC > num - 1 || nowR > num - 1) break;

        arr[nowR][nowC] = 0;
      }
    }
  }

  dfs(idx + 1, dist, conn);
}

int main() {
  int tcs;
  cin >> tcs;

  for (int t = 1; t <= tcs; t++) {
    cin >> num;
    Cores.clear();

    for (int i = 0; i < num; i++) {
      for (int j = 0; j < num; j++) {
        cin >> arr[i][j];

        if (arr[i][j] == 1 && i != 0 && i != num - 1 && j != 0 &&
            j != num - 1) {
          Core tmp{i, j};
          Cores.push_back(tmp);
        }
      }
    }

    maxi = 0;
    minDist = 1e9;
    dfs(0, 0, 0);

    cout << "#" << t << " " << minDist << "\n";
  }
}
