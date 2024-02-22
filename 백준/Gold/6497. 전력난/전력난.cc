#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Edge {
  int a, b, val;
};

vector<Edge> lines;

bool compare(Edge &left, Edge &right) { return left.val < right.val; }

vector<int> arr;
int n, m, cnt, val, sum;

int find(int tar) {
  if (tar == arr[tar])
    return tar;
  int ret = find(arr[tar]);
  arr[tar] = ret;
  return ret;
}

void setUnion(int a, int b) {
  int t1 = find(a);
  int t2 = find(b);
  if (t1 == t2)
    return;
  if (t1 < t2)
    arr[t2] = t1;
  else
    arr[t1] = t2;
}

int main() {
  while (true) {
    cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    arr.resize(n + 2);
    for (int i = 0; i <= n + 1; i++) {
      arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
      int a, b, val;
      cin >> a >> b >> val;
      sum += val;
      lines.push_back({a, b, val});
    }

    sort(lines.begin(), lines.end(), compare);

    for (Edge line : lines) {
      if (find(line.a) == find(line.b))
        continue;
      setUnion(line.a, line.b);
      val += line.val;
      cnt++;
      if (cnt == n - 1)
        break;
    }
    cout << sum - val << "\n";

    arr.clear();
    lines.clear();
    cnt = 0;
    val = 0;
    sum = 0;
  }
}