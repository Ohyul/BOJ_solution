#include <iostream>
typedef long long ll;
using namespace std;

ll n, m;
ll arr[1000010], segTree[1000010 * 4];
ll strIdx;

void init() {
    strIdx = 1;
    while (strIdx < n) strIdx <<= 1;
    for (ll i = 0; i < n; i++) {
        segTree[i + strIdx] = arr[i];
    }
    for (ll i = strIdx - 1; i >= 1; i--) {
        segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
    }
}

void query(ll from, ll to) {
    ll sum = 0;
    from += strIdx;
    to += strIdx;
    for (from, to; from != to; from >>= 1, to >>= 1) {
        if (from & 1) {
            sum += segTree[from];
            from++;
        }
        if (to & 1) {
            to--;
            sum += segTree[to];
        }
    }
    cout << sum << "\n";
}

void update(ll idx, ll val) {
    idx += strIdx;
    segTree[idx] = val;
    idx >>= 1;
    while (idx >= 1) {
        segTree[idx] = segTree[idx << 1] + segTree[(idx << 1) | 1];
        idx >>= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (ll i = 0; i < n; i++) {
        arr[i] = 0;
    }
    init();
    for (ll i = 0; i < m; i++) {
        ll inst;
        cin >> inst;
        if (inst == 0) {
            ll from, to;
            cin >> from >> to;
            if (from <= to) {
                query(from - 1, to);
            }
            else {
                swap(from, to);
                query(from - 1, to);
            }
        }
        if (inst == 1) {
            ll idx, val;
            cin >> idx >> val;
            update(idx - 1, val);
        }
    }
}
