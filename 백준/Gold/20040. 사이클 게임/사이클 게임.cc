#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
int n, m;

int find(int x) { return (x == parent[x]) ? x : (parent[x] = find(parent[x])); }

void unionSets(int x, int y) {
  x = find(x);
  y = find(y);

  if (x < y) {
    parent[y] = x;
  } else {
    parent[x] = y;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;

  parent.resize(n);
  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;

    if (find(x) == find(y)) {
      cout << i + 1 << "\n";
      return 0;
    } else {
      unionSets(x, y);
    }
  }

  cout << 0 << "\n";
}