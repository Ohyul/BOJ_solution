#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> v;
int n, tar, cnt;

void dfs(int now) {
  v[now] = -1e9;
  for (int i = 0; i < v.size(); ++i) {
    if (now == v[i]) {
      dfs(i);
    }
  }
}

int main() {
  cin >> n;
  v.resize(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  cin >> tar;
  dfs(tar);

  for (int i = 0; i < n; ++i) {
    if (v[i] != -1e9 && find(v.begin(), v.end(), i) == v.end()) {
      cnt++;
    }
  }
  cout << cnt;
}