#include <algorithm>
#include <iostream>

using namespace std;

pair<long long, long long> p[100000];
bool comparePair(const pair<long long, long long> &a,
                 const pair<long long, long long> &b) {
  if (a.second != b.second) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main() {
  long long n;
  cin >> n;
  long long cnt = 0;
  long long srt_time = 0;

  for (long long i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
  }

  sort(p, p + n, comparePair);

  for (long long meeting = 0; meeting < n; meeting++) {
    if (p[meeting].first >= srt_time) {
      cnt++;
      srt_time = p[meeting].second;
    }
  }
  cout << cnt;
  return 0;
}
