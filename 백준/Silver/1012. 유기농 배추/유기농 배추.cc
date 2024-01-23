#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int arr[51][51];
bool visited[51][51];
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

pair<int, int> p;
queue<pair<int, int>> q;

int main() {
  int n;
  cin >> n;
  while (n > 0) {
    int col = 0, row = 0, k = 0, cnt = 0;
    cin >> col >> row >> k;
    for (int i = 0; i < 51; i++) {
      for (int j = 0; j < 51; j++) {
        arr[i][j] = 0;
        visited[i][j] = 0;
      }
    }
    for (int i = 0; i < k; i++) {
      int y, x;
      cin >> y >> x;
      arr[y][x] = 1;
    }

    for (int i = 0; i < col; i++) {
      for (int j = 0; j < row; j++) {
        if (arr[i][j] == 1 && visited[i][j] == 0) {
          cnt++;
          visited[i][j] = 1;
          q.push(make_pair(i, j));

          while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for (int d = 0; d < 4; d++) {
              int newR = r + dr[d];
              int newC = c + dc[d];

              if (newR >= 0 && newR < col && newC >= 0 && newC < row &&
                  arr[newR][newC] == 1) {
                if (visited[newR][newC] == 0) {
                  visited[newR][newC] = 1;
                  q.push(make_pair(newR, newC));
                }
              }
            }
          }
        }
      }
    }

    cout << cnt << "\n";
    n--;
  }

  return 0;
}