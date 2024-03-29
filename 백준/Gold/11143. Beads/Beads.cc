#include <iostream>
typedef long long ll;
using namespace std;

int t,each, n, m, k;
ll arr[1000100];
ll segTree[1000100 * 4];
ll strIdx;

void init() {
	strIdx = 1;
	while (strIdx < n) strIdx *= 2;

	for (int i = 0; i < n; i++) {
		segTree[i + strIdx] = arr[i];
	}
	for (int i = n + strIdx; i < (strIdx << 1); i++) {
		segTree[i] = 0;
	}

	for (int i = strIdx - 1; i > 0; i--) {
		segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
	}
}

void update(ll idx, ll val) {
	arr[idx] += val;
	segTree[idx + strIdx] += val;
	ll i = (idx + strIdx) >> 1;

	while (i >= 1) {
		segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
		i = i >> 1;
	}
}

void query(ll left, ll right) {
	ll sum = 0;
	for (left += strIdx, right += strIdx; left != right; left >>= 1, right >>= 1) {
		if (left & 1) {
			sum += segTree[left];
			left++;
		}
		if (right & 1) {
			right--;
			sum += segTree[right];
		}
	}

	cout << sum << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (each++ < t) {
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			arr[i] = 0;
		}
		init();

		for (int i = 0; i < m + k; i++) {
			char inst;
			cin >> inst;
			if (inst == 'P') {
				ll idx, val;
				cin >> idx >> val;
				update(idx - 1, val);
			}
			else if (inst == 'Q') {
				ll from, to;
				cin >> from >> to;
				query(from - 1, to);
			}
		}
	}
}