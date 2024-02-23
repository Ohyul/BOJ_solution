#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

struct Edge {
  ll a, b, val;
};

bool compare(Edge &left, Edge &right) { return left.val < right.val; }

vector<Edge> lines;

vector<ll> arr;
ll n, m;
ll cnt, sum, val, flag;

ll find(ll tar) {
  if (tar == arr[tar])
    return tar;
  ll ret = find(arr[tar]);
  arr[tar] = ret;
  return ret;
}

void setUnion(ll a, ll b) {
  ll t1 = find(a);
  ll t2 = find(b);
  if (t1 == t2)
    return;
  if (t1 < t2)
    arr[t2] = t1;
  else
    arr[t1] = t2;
}

int main() {
  cin >> n >> m;
  arr.resize(n + 10);
  for (int i = 0; i < m; i++) {
    ll a, b, val;
    cin >> a >> b >> val;
    sum += val;
    lines.push_back({a, b, val});
  }
  for (int i = 0; i <= n + 2; i++) {
    arr[i] = i;
  }
  sort(lines.begin(), lines.end(), compare);

  for (Edge line : lines) {
    if (find(line.a) == find(line.b))
      continue;
    setUnion(line.a, line.b);
    val += line.val;
    cnt++;
    if (cnt == n - 1) {
      flag = 1;
      break;
    }
  }
  if (flag == 1)
    cout << sum - val;
  else
    cout << "-1";
}