#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m;
vector<int> node[1010];
int used[1010];
int cnt;
queue<int> q;

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int srt, dst;
    cin >> srt >> dst;
    node[srt].push_back(dst);
    node[dst].push_back(srt);
  }
  for (int i = 1; i <= n; i++) {
    if (node[i].size() > 0 && used[i] == 0) {
      used[i] = 1;
      q.push(i);
      while (!q.empty()) {
        int now = q.front();
        q.pop();
        for (int next : node[now]) {
          if (used[next] == 1)
            continue;
          used[next] = 1;
          q.push(next);
        }
      }
      cnt++;
    }
    if (node[i].size() == 0 && used[i] == 0) {
      used[i] = 1;
      cnt++;
    }
  }
  cout << cnt;
}