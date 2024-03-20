#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

vector<ll> a;
ll n, m;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

int main() {
    cin >> n >> m;

    a.resize(m);

    for (int i = 0; i < m; ++i) {
        cin >> a[i];
    }

    ll ans = 0;
    for (int mask = 1; mask < (1 << m); ++mask) {
        ll mult = 1;
        int cnt = 0;
        for (int j = 0; j < m; ++j) {
            if (mask & (1 << j)) {
                ++cnt;
                mult = lcm(mult, a[j]);
                if (mult > n) break;
            }
        }
        if (cnt % 2 == 1) {
            ans += n / mult;
        }
        else {
            ans -= n / mult;
        }
    }

    cout << n - ans;
}
