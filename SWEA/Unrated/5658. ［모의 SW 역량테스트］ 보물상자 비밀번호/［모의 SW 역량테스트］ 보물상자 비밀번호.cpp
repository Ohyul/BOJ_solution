#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>
using namespace std;

int n, k;
string input, arr[4];
set<string> s;
int cases, each;

int main() {
  cin >> cases;
  while (each++ < cases) {
    cin >> n >> k;
    cin >> input;

    int len = input.length();
    int idx = 0;
    while (idx < len / 4) {
      for (int i = 0; i < 4; i++) {
        arr[i] = "";
        for (int j = 0; j < n / 4; j++) {
          arr[i].push_back(input[(j + (n / 4 * i) + idx) % len]);
        }
        s.insert(arr[i]);
      }
      idx++;
    }

    vector<string> v;
    for (auto word : s) {
      v.push_back(word);
    }

    string ansS = v[v.size() - k];
    int ans = stoi(ansS, 0, 16);
    cout << "#" << each << " " << ans << "\n";
    v.clear();
    s.clear();
  }
}
