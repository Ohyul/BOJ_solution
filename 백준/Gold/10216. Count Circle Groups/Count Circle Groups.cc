#include <iostream>
#include <vector>
using namespace std;

struct Circle {
  int x, y, r;
};

int num;
vector<int> parent;

int find(int tar) {
  if (parent[tar] == tar)
    return tar;
  return parent[tar] = find(parent[tar]);
}

void setUnion(int a, int b) {
  int t1 = find(a);
  int t2 = find(b);
  if (t1 != t2)
    parent[t2] = t1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int test;
  cin >> test;

  for (int t = 0; t < test; t++) {
    cin >> num;
    vector<Circle> circles(num);

    parent.resize(num);
    for (int i = 0; i < num; i++) {
      parent[i] = i;
      cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }

    int result = num;

    for (int i = 0; i < num - 1; i++) {
      for (int j = i + 1; j < num; j++) {
        long long d1 =
            (circles[i].r + circles[j].r) * (circles[i].r + circles[j].r);
        long long d2 =
            (circles[i].x - circles[j].x) * (circles[i].x - circles[j].x) +
            (circles[i].y - circles[j].y) * (circles[i].y - circles[j].y);

        if (d1 >= d2 && find(i) != find(j)) {
          setUnion(i, j);
          result--;
        }
      }
    }

    cout << result << '\n';
  }
}