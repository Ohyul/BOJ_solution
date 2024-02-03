#include <iostream>
#include <set>
using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int cases, k, n;
  char op;

  cin >> cases;

  while (cases--) {
    cin >> k;

    multiset<int> numbers;

    for (int i = 0; i < k; i++) {
      cin >> op >> n;
      if (op == 'I') {
        numbers.insert(n);
      } else if (op == 'D') {
        if (!numbers.empty()) {
          if (n == 1) {
            auto it = numbers.end();
            --it;
            numbers.erase(it);
          } else if (n == -1) {
            numbers.erase(numbers.begin());
          }
        }
      }
    }

    if (numbers.empty()) {
      cout << "EMPTY\n";
    } else {
      auto it = numbers.end();
      --it;
      cout << *it << " " << *numbers.begin() << "\n";
    }
  }

  return 0;
}
