#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, Odd, cnt = 1;
vector<int> arr;

int main() {
  cin >> N;
  arr.resize(N + 1);

  if (N == 1) {
    cout << "koosaga";
    return 0;
  }

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < N; i++) {
    if (arr[i] == arr[i - 1]) {
      cnt++;
    } else {
      if (cnt % 2 == 1) {
        Odd = 1;
        break;
      }

      cnt = 1;
    }
  }

  if (cnt % 2 == 1) {
    Odd = 1;
  }

  cout << (Odd ? "koosaga" : "cubelover");
}