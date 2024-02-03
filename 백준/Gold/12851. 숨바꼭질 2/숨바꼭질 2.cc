#include <climits>
#include <iostream>
#include <queue>

using namespace std;

int dx[] = {-1, 1, 2};
int cnt = 0, res = INT_MAX;

void bfs(int start, int destination) {
  queue<int> q;
  int move[100001] = {0};
  q.push(start);

  while (!q.empty()) {
    int pos = q.front();
    q.pop();

    if (res < move[pos])
      return;

    if (move[pos] <= res && pos == destination) {
      res = move[pos];
      cnt++;
    }

    for (int i = 0; i < 3; i++) {
      int next;
      if (i == 2) {
        next = pos * dx[i];
      } else {
        next = pos + dx[i];
      }

      if (next >= 0 && next < 100001) {
        if (move[next] == 0 || move[next] >= move[pos] + 1) {
          move[next] = move[pos] + 1;
          q.push(next);
        }
      }
    }
  }
}

int main() {
  int n, k;
  cin >> n >> k;

  bfs(n, k);

  cout << res << "\n" << cnt;

  return 0;
}