#include <iostream>
typedef long long ll;
using namespace std;

ll arr[100010], segTree[100010 * 4];
ll n, q;
ll strIdx;

void init() {
    strIdx = 1;
    while (strIdx < n) {
        strIdx <<= 1;
    }
    for (ll i = 0; i < n; i++) {
        segTree[i + strIdx] = arr[i];
    }
    for (ll i = strIdx - 1; i >= 1; i--) {
        segTree[i] = segTree[i << 1] + segTree[(i << 1) | 1];
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
    arr[idx] = val;
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


    cin >> n >> q;
    for (ll i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init();

    for (ll i = 0; i < q; i++) {
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if (x <= y) {
            query(x - 1, y);
        }
        else {
            query(y - 1, x);
        }
        update(a - 1, b);
    }
}
