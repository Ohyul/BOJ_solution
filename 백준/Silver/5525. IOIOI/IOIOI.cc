#include <iostream>
using namespace std;
int main() {
  int p, n;
  string str;
  cin >> p >> n >> str;
  int ans = 0;

  for (int i = 0; i < n; i++) {
    int cnt = 0;
    if (str[i] == 'I') {
      while (str[i + 1] == 'O' && str[i + 2] == 'I') {
        cnt++;
        if (cnt == p) {
          ans++;
          cnt--;
        }
        i += 2;
      }
    }
  }

  cout << ans;
}