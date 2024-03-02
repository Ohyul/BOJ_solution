#include <iostream>
#include <vector>
using namespace std;

int n, l;

int valid(vector<vector<int>> &map) {
  int validCnt = 0;

  for (int i = 0; i < n; i++) {
    int currHeight = map[i][0];
    bool isValid = true;

    for (int j = 1; j < n; j++) {
      if (currHeight == map[i][j]) {
        continue;
      } else if (currHeight == map[i][j] + 1) {
        currHeight--;
        for (int k = j; k < j + l; k++) {
          if (k >= n || currHeight != map[i][k]) {
            isValid = false;
            break;
          }
          map[i][k] = -1;
        }
        if (!isValid) {
          break;
        } else {
          j += l - 1;
        }
      } else if (currHeight == map[i][j] - 1) {
        currHeight++;
        for (int k = j - 1; k > j - l - 1; k--) {
          if (k < 0 || currHeight != map[i][k] + 1) {
            isValid = false;
            break;
          }
          map[i][k] = -1;
        }
        if (!isValid) {
          break;
        }
      } else {
        isValid = false;
        break;
      }
    }

    if (isValid) {
      validCnt++;
    }
  }

  return validCnt;
}

int main() {
  cin >> n >> l;

  vector<vector<int>> map(n, vector<int>(n, 0));
  vector<vector<int>> turnedMap(n, vector<int>(n, 0));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
      turnedMap[j][i] = map[i][j];
    }
  }

  int ret = valid(map) + valid(turnedMap);

  cout << ret;
}