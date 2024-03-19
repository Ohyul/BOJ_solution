#include <iostream>
using namespace std;

int n, m;
int arr[100100], segTree[100100 * 4];
int strIdx;


void init() {
	strIdx = 1;
	while (strIdx < n) strIdx *= 2;

	for (int i = 0; i < n ; i++) {
		segTree[i + strIdx] = arr[i];
	}
	for (int i = n + strIdx; i <= 2 * strIdx - 1; i++) {
		segTree[i] = 1e9;
	}

	for (int i = strIdx - 1; i >= 1; i--) {
		segTree[i] = min(segTree[i << 1], segTree[i << 1 | 1]);
	}
}

void query(int left, int right) {
	int mini = 1e9;
	left += strIdx;
	right += strIdx;
	for (left, right; left != right; left >>= 1, right >>= 1) {
		if (left & 1) {
			mini = min(mini, segTree[left]);
			left++;
		}
		if (right & 1) {
			right--;
			mini = min(mini, segTree[right]);
		}
	}
	cout << mini << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init();

	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		query(l-1, r);
	}
}