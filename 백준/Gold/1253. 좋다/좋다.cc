#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, input;
int str, dst, ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> input;
    v.push_back(input);
  }

  if (n <= 2) {
    cout << 0;
    return 0;
  }

  sort(v.begin(), v.end());

  for (int i = 0; i < n; i++) {
    vector<int> arr = v;
    arr.erase(arr.begin() + i);

    str = 0;
    dst = n - 2;

    while (str < dst) {
      int sum = arr[str] + arr[dst];

      if (sum == v[i]) {
        ans++;
        break;
      }

      if (sum < v[i])
        str++;
      else
        dst--;
    }
  }

  cout << ans;
}