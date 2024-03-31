#include <iostream>
#include <climits>
using namespace std;

int arr[1000010], segTree[1000010 * 4];
int n, m;
int strIdx;

void init() {
	strIdx = 1;
	while (strIdx < n) strIdx <<= 1;
	for (int i = 0; i < n; i++) {
		segTree[i + strIdx] = arr[i];
	}
	for (int i = strIdx - 1; i >= 1; i--) {
		segTree[i] = max(segTree[i << 1], segTree[i << 1 | 1]);
	}
}

void query(int from, int to) {
	int maxi = INT_MIN;
	for (from += strIdx, to += strIdx; from != to; from >>= 1, to >>= 1) {
		if (from & 1) {
			maxi = max(maxi, segTree[from]);
			from++;
		}
		if (to & 1) {
			to--;
			maxi = max(maxi, segTree[to]);
		}
	}
	cout << maxi << " ";
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
	for (int i = m-1; i < n - m + 1; i++) {
		int from = i - m + 1, to = i + m;
		query(from, to );
	}
}