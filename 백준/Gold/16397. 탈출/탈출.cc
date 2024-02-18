#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

bool used[100100];
int n, t, g;

int bfs(int n, int t, int g) {
  queue<int> q;
  int step = 0;

  q.push(n);
  used[n] = true;

  while (!q.empty()) {
    int size = q.size();

    for (int i = 0; i < size; ++i) {
      int cur = q.front();
      q.pop();

      if (cur == g) {
        return step;
      }

      if (cur * 2 > 99999) {
        if (!used[cur + 1]) {
          q.push(cur + 1);
          used[cur + 1] = true;
        }
      } else {
        string m_str = to_string(cur * 2);
        if (m_str[0] != '0') {
          m_str[0] = char(int(m_str[0]) - 1);
        }

        int m = stoi(m_str);
        if (!used[cur + 1]) {
          q.push(cur + 1);
          used[cur + 1] = true;
        }
        if (!used[m]) {
          q.push(m);
          used[m] = true;
        }
      }
    }

    step++;

    if (step > t) {
      break;
    }
  }

  return -1;
}

int main() {
  cin >> n >> t >> g;

  fill(used, used + 100001, false);

  int result = bfs(n, t, g);

  if (result == -1) {
    cout << "ANG"
         << "\n";
  } else {
    cout << result << "\n";
  }
}