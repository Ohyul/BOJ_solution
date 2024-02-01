#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <string>

using namespace std;
struct Regi {
  int now;
  string func;
};

int str, dst;
string func;
int used[10100];
queue<Regi> q;
string ans;

int cases;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> cases;
  while (cases > 0) {
    for (int i = 0; i < 10100; i++) {
      used[i] = 0;
    }
    ans = "";
    cin >> str >> dst;
    used[str] = 1;
    q.push({str, ""});

    while (!q.empty()) {
      int now = q.front().now;
      string func = q.front().func;
      q.pop();

      if (now == dst) {
        cout << func << "\n";
      }

      if (used[(now * 2) % 10000] == 0) {
        used[(now * 2) % 10000] = 1;
        q.push({(now * 2) % 10000, func + 'D'});
      }

      if (now == 0 && used[9999] == 0) {
        used[9999] = 1;
        q.push({9999, func + 'S'});
      } else if (now != 0 && used[now - 1] == 0) {
        used[now - 1] = 1;
        q.push({now - 1, func + 'S'});
      }

      int left = (now % 1000) * 10 + (now / 1000);
      if (used[left] == 0) {
        used[left] = 1;
        q.push({left, func + 'L'});
      }

      int right = now / 10 + (now % 10) * 1000;
      if (used[right] == 0) {
        used[right] = 1;
        q.push({right, func + 'R'});
      }
    }
    cases--;
  }
}