#include <iostream>
#include <vector>
using namespace std;

using pii = pair<int, int>;
vector<int> arr;

void toPostorder(int node, int thres) {
  int right = node + 1;
  while (right <= thres && arr[right] < arr[node])
    ++right;
  int left = node + 1;
  if (left < right)
    toPostorder(left, right - 1);
  if (right <= thres)
    toPostorder(right, thres);
  cout << arr[node] << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  while (cin >> n)
    arr.push_back(n);

  int len = arr.size();
  toPostorder(0, len - 1);
  return 0;
}
