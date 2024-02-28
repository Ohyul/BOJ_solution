#include <iostream>
using namespace std;

int arr[100100], par[100100];
int n, m, cnt, flag;

int find(int tar) {
  if (tar == par[tar])
    return tar;
  int ret = find(par[tar]);
  par[tar] = ret;
  return ret;
}

void setUnion(int a, int b) {
  int t1 = find(a);
  int t2 = find(b);
  if (t1 == t2)
    return;
  if (t1 < t2)
    par[t2] = t1;
  else
    par[t1] = t2;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }

  flag = 0;

  for (int i = 0; i < m; i++) {
    int input;
    cin >> input;
    if (find(input) == 0)
      flag = 1;
    else {
      setUnion(find(input) - 1, input);
      if (flag == 0)
        cnt++;
    }
  }

  cout << cnt;
}
