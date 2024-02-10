#include <iostream>
#include <queue>
#include <set>
#include <vector>

using namespace std;

#define MAX 1010

int n, m;
int grid[MAX][MAX];
int areaNum[MAX][MAX];
int num;
int result[MAX][MAX];
int used[MAX][MAX];
vector<int> v;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void bfs(int row, int col) {
  queue<pair<int, int>> q;
  q.push({row, col});
  int count = 1;
  areaNum[row][col] = num;
  used[row][col] = 1;

  while (!q.empty()) {
    int currRow = q.front().first;
    int currCol = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextRow = currRow + dx[i];
      int nextCol = currCol + dy[i];

      if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < m &&
          grid[nextRow][nextCol] == 0 && !used[nextRow][nextCol]) {
        used[nextRow][nextCol] = 1;
        areaNum[nextRow][nextCol] = num;
        q.push({nextRow, nextCol});
        count++;
      }
    }
  }
  v.push_back(count);
}

void solution() {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (grid[row][col] == 0 && !used[row][col]) {
        bfs(row, col);
        num++;
      }
    }
  }

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      if (grid[row][col] == 1) {
        set<int> search;

        for (int k = 0; k < 4; k++) {
          int nextRow = row + dx[k];
          int nextCol = col + dy[k];

          if (nextRow >= 0 && nextCol >= 0 && nextRow < n && nextCol < m &&
              grid[nextRow][nextCol] == 0) {
            if (search.find(areaNum[nextRow][nextCol]) == search.end()) {
              search.insert(areaNum[nextRow][nextCol]);
              result[row][col] += v[areaNum[nextRow][nextCol]];
            }
          }
        }
        result[row][col]++;
        result[row][col] %= 10;
      }
    }
  }

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      cout << result[row][col];
    }
    cout << endl;
  }
}

int main() {
  cin >> n >> m;
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < m; col++) {
      char c;
      cin >> c;
      grid[row][col] = c - '0';
    }
  }

  solution();

  return 0;
}