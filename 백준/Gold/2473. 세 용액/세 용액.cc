#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
typedef long long ll;
using namespace std;

ll n;
ll mini = LLONG_MAX;
ll a, b, c;
vector<ll> v(n);
int flag = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for (ll i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (ll i = 0; i < n - 2; i++) {
        if (flag == 1) break;
        ll l = i + 1, r = n - 1;
        while (l < r) {
            ll sum = v[l] + v[i] + v[r];
            if (abs(sum) < mini) {
                mini = abs(sum);
                a = v[i], b = v[l], c = v[r];
            }
            if (sum == 0) {
                flag = 1;
                break;
            }
            else if (sum < 0) {
                l++;
            }
            else {
                r--;
            }
        }
    }

    vector<ll> ans = { a, b, c };
    sort(ans.begin(), ans.end());

    for (auto el : ans) {
        cout << el << " ";
    }
}
