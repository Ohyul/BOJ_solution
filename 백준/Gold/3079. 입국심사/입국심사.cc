#include <algorithm>
#include <iostream>
#include <vector>

typedef unsigned long long ull;
using namespace std;

int main() {
  ull n, m, ans = 0;
  vector<ull> v;

  cin >> n >> m;
  v.resize(n);
  for (ull i = 0; i < n; i++)
    cin >> v[i];

  sort(v.begin(), v.end());

  ull dst = m * v.back();
  ull str = 1;
  ull mid;

  while (str <= dst) {
    mid = (dst + str) / 2;
    ull sum = 0;

    for (ull i = 0; i < v.size(); i++)
      sum += (mid / v[i]);

    if (sum >= m) {
      dst = mid - 1;
      ans = mid;
    } else {
      str = mid + 1;
    }
  }

  cout << ans;
}