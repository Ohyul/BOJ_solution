#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

struct House {
  int row, col, val;
};

vector<House> Houses;
int n, m, maxi;
int arr[22][22];
int tcs, tc;

int main() {
  cin >> tcs;
  while (tc++ < tcs) {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
        if (arr[i][j] == 1) Houses.push_back({i, j, m});
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int len = 60;
        while (len >= 1) {
          int cost = (len * len) + ((len - 1) * (len - 1));
          int demand = 0;
          int cnt = 0;
          for (const auto& house : Houses) {
            if (abs(house.row - i) + abs(house.col - j) < len) {
              demand += house.val;
              cnt++;
            }
          }
          if (demand >= cost) {
            maxi = max(cnt, maxi);
            break;
          } else {
            len--;
          }
        }
      }
    }
    cout << "#" << tc << " " << maxi << "\n";
    maxi = 0;
    Houses.clear();
  }
}