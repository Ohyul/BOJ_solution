#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int n, m, q;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> q;

  vector<ll> add_input[2001];
  vector<ll> hidden[2001];
  ll weight[2001];
  ll weight_print;
  vector<ll> input[2001];
  ll multiple_input[2001];

  // Hidden layer input
  for (int i = 1; i <= m; i++) {
    int c;
    cin >> c;
    for (int j = 1; j <= c; j++) {
      int x;
      cin >> x;
      add_input[i].push_back(x);
    }
    for (int j = 1; j <= c; j++) {
      int x;
      cin >> x;
      hidden[i].push_back(x);
    }
    cin >> weight[i];
  }

  // Output layer input
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    for (int j = 0; j < add_input[i].size(); j++) {
      multiple_input[add_input[i][j]] += (hidden[i][j] * x);
    }
    weight[i] *= x;
  }

  cin >> weight_print;

  // Input layer input
  for (int i = 1; i <= q; i++) {
    for (int j = 1; j <= n; j++) {
      int x;
      cin >> x;
      input[i].push_back(x);
    }
  }

  // Solve function
  ll sum_last = 0;
  for (int i = 1; i <= m; i++) {
    sum_last += weight[i];
  }
  sum_last += weight_print;

  for (int i = 1; i <= q; i++) {
    ll sum = 0;
    for (int j = 1; j <= n; j++) {
      sum += input[i][j - 1] * multiple_input[j];
    }
    sum += sum_last;
    cout << sum << "\n";
  }

  return 0;
}