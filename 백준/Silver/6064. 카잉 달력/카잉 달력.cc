#include <iostream>

using namespace std;

int gcd(int a, int b) {
  while (b != 0) {
    int r = a % b;
    a = b;
    b = r;
  }
  return a;
}

int lcm(int a, int b) { return a * b / gcd(a, b); }

int main() {
  int cases;
  cin >> cases;
  while (cases > 0) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;

    int cnt = x % (m + 1);
    int dy = x;

    for (int i = 0; i < n; i++) {
      int ty = dy % n == 0 ? n : dy % n;
      if (ty == y) {
        break;
      }
      dy = ty + m;
      cnt += m;
    }

    cout << (cnt > lcm(m, n) ? -1 : cnt) << endl;

    cases--;
  }
}