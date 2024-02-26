#include <algorithm>
#include <iostream>
#include <vector>
typedef unsigned long long ull;
using namespace std;

int n, k, ans;
vector<ull> v;

int main() {
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    ull input;
    cin >> input;
    v.push_back(input);
  }

  sort(v.begin(), v.end());

  ull str = 1;
  ull dst = v[n - 1] * k;
  ull mid = 0;
  while (str <= dst) {
    mid = (str + dst) / 2;
    ull cnt = 1, first = v[0];
    for (int i = 0; i < n; i++) {
      if (v[i] - first >= mid) {
        first = v[i];
        cnt++;
      }
    }
    if (cnt >= k) {
      str = mid + 1;
      ans = mid;
    } else {
      dst = mid - 1;
    }
  }
  cout << ans;
}
