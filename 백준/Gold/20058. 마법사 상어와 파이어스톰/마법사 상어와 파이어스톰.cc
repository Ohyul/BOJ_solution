#include <iostream>
#include <queue>
#include <vector>
#define MAX 70

using namespace std;

int n, q, sumAnswer, sizeAnswer;
int map[MAX][MAX];
bool visit[MAX][MAX];
vector<int> cmd;
int dr[] = {0, 0, 1, -1};
int dc[] = {1, -1, 0, 0};

int max(int a, int b) { return a > b ? a : b; }

void input() {
  cin >> n >> q;
  n = (1 << n);

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      cin >> map[row][col];
      sumAnswer += map[row][col];
    }
  }

  for (int i = 0; i < q; i++) {
    int a;
    cin >> a;
    cmd.push_back(a);
  }
}

void turning(int a, int b, int len) {
  int square = len / 2;

  for (int number = 0; number < square; number++) {
    int startR = a + number;
    int startC = b + number;
    int endR = a + len - number - 1;
    int endC = b + len - number - 1;

    int nextR = endR;
    int nextC = startC;
    int idx = 0;

    vector<int> temp;

    for (int row = startR; row < endR; row++)
      temp.push_back(map[row][startC]);

    for (int row = startR; row < endR; row++)
      map[row][startC] = map[endR][nextC++];

    for (int col = startC; col < endC; col++)
      map[endR][col] = map[nextR--][endC];

    for (int row = endR; row > startR; row--)
      map[row][endC] = map[startR][nextC--];

    for (int col = endC; col > startC; col--)
      map[startR][col] = temp[idx++];
  }
}

void remakeMap(int len) {
  for (int row = 0; row < n; row += len) {
    for (int col = 0; col < n; col += len) {
      turning(row, col, len);
    }
  }
}

void meltingIce() {
  vector<pair<int, int>> v;

  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (map[row][col] == 0)
        continue;

      int cnt = 0;

      for (int i = 0; i < 4; i++) {
        int nextR = row + dr[i];
        int nextC = col + dc[i];

        if (nextR < 0 || nextC < 0 || nextR >= n || nextC >= n)
          continue;

        if (map[nextR][nextC] == 0)
          continue;

        cnt++;
      }

      if (cnt < 3)
        v.push_back(make_pair(row, col));
    }
  }

  for (int i = 0; i < v.size(); i++) {
    int row = v[i].first;
    int col = v[i].second;
    map[row][col]--;
    sumAnswer--;
  }
}

int bfs(int a, int b) {
  queue<pair<int, int>> q;
  q.push(make_pair(a, b));
  visit[a][b] = true;
  int cnt = 1;

  while (!q.empty()) {
    int row = q.front().first;
    int col = q.front().second;
    q.pop();

    for (int i = 0; i < 4; i++) {
      int nextR = row + dr[i];
      int nextC = col + dc[i];

      if (nextR >= 0 && nextC >= 0 && nextR < n && nextC < n) {
        if (map[nextR][nextC] != 0 && !visit[nextR][nextC]) {
          visit[nextR][nextC] = true;
          q.push(make_pair(nextR, nextC));
          cnt++;
        }
      }
    }
  }

  return cnt;
}

void calculateIceSize() {
  for (int row = 0; row < n; row++) {
    for (int col = 0; col < n; col++) {
      if (map[row][col] == 0)
        continue;

      if (!visit[row][col]) {
        int result = bfs(row, col);
        sizeAnswer = max(sizeAnswer, result);
      }
    }
  }
}

void solution() {
  for (int i = 0; i < q; i++) {
    int len = (1 << cmd[i]);
    remakeMap(len);
    meltingIce();
  }

  calculateIceSize();

  cout << sumAnswer << "\n" << sizeAnswer << "\n";
}

void solve() {
  input();
  solution();
}

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  solve();

  return 0;
}