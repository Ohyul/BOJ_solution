#include <iostream>
typedef long long ll;
using namespace std;

ll arr[1000010], segTree[2000020];
ll n, m, k;
ll strIdx;

void init() {
    strIdx = 1;
    while (strIdx < n) strIdx <<= 1;
    for (ll i = 0; i < n; i++) {
        segTree[i + strIdx] = arr[i];
    }
    for (ll i = strIdx - 1; i >= 1; i--) {
        segTree[i] = (segTree[i << 1] * segTree[(i << 1) | 1]) % 1000000007;
    }
}

void update(ll idx, ll val) {
    idx += strIdx;
    segTree[idx] = val;
    idx >>= 1;
    while (idx >= 1) {
        segTree[idx] = (segTree[idx << 1] * segTree[(idx << 1) | 1]) % 1000000007;
        idx >>= 1;
    }
}

void query(ll from, ll to) {
    ll res = 1;
    from += strIdx;
    to += strIdx;
    while (from <= to) {
        if (from % 2 == 1) {
            res = (res * segTree[from]) % 1000000007;
            from++;
        }
        if (to % 2 == 0) {
            res = (res * segTree[to]) % 1000000007;
            to--;
        }
        from >>= 1;
        to >>= 1;
    }
    cout << res << "\n";
}

int main() {
    cin >> n >> m >> k;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init();

    for (ll i = 0; i < m + k; i++) {
        ll inst;
        cin >> inst;
        if (inst == 1) {
            ll idx, val;
            cin >> idx >> val;
            update(idx - 1, val);
        }
        if (inst == 2) {
            ll from, to;
            cin >> from >> to;
            query(from - 1, to - 1);
        }
    }
}
