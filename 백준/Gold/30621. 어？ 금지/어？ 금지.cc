#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
typedef long long ll;
using namespace std;

int n;
vector <int> t, b;
vector <ll> dp;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n;

    t.resize(n), b.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    
    dp.resize(n);
    cin >> dp[0];

    for (int i = 1; i < n; i++){
        ll input; 
        cin >> input;
        int prev(lower_bound(t.begin(), t.begin() + i + 1, t[i] - b[i]) - t.begin());

        dp[i] = max(dp[i - 1], input);
        if (!!~--prev) dp[i] = max(dp[i], dp[prev] + input);
    }

    cout << dp[n - 1];
}
