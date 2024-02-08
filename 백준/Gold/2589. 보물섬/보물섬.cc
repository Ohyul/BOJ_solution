#include <iostream>
#include <queue>
using namespace std;

struct Node {
  int row, col, val;
};

queue<Node> q;

char arr[55][55];
int used[55][55];
int n, m;

vector<Node> v;
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int maxi = 0;

int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string str;
    cin >> str;
    for (int j = 0; j < m; j++) {
      arr[i][j] = str[j];
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (arr[i][j] == 'L' && used[i][j] == 0) {
        used[i][j] = 1;
        q.push({i, j, 0});
        while (!q.empty()) {
          Node now = q.front();
          maxi = max(maxi, now.val);
          q.pop();
          for (int k = 0; k < 4; k++) {
            int nextR = now.row + dr[k];
            int nextC = now.col + dc[k];
            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m)
              continue;
            if (arr[nextR][nextC] == 'W' || used[nextR][nextC] == 1)
              continue;
            used[nextR][nextC] = 1;
            q.push({nextR, nextC, now.val + 1});
          }
        }
        for (int r = 0; r < n; r++) {
          for (int c = 0; c < m; c++) {
            used[r][c] = 0;
          }
        }
      }
    }
  }
  cout << maxi;
}