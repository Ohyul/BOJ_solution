#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int arr[17][17];
int n, mini = 1e9;
int sum1, sum2;
int ingre[17];
int cases, each;

int calc(int tar) {
  int rev = tar;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    v.push_back(rev % 2);
    rev /= 2;
    ingre[n - i - 1] = v[i];
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (ingre[i] == 1 && ingre[j] == 1) {
        sum += arr[i][j];
      }
    }
  }
  return sum;
}

int main() {
  cin >> cases;
  while (each++ < cases) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
      }
    }
    int bits = n;
    for (int i = 1; i < (1 << bits) / 2; i++) {
      int syn1 = i;
      int syn2 = (1 << bits) - syn1 - 1;
      sum1 = calc(syn1);
      sum2 = calc(syn2);
      mini = min(mini, abs(sum1 - sum2));
    }
    cout << "#" << each << " " << mini << "\n";
    mini = 1e9;
  }
}
