#include <iostream>
using namespace std;

int arr[500010], segTree[500010 * 4];
int strIdx;
int n, q;


void init() {
	strIdx = 1;
	while (strIdx < n) strIdx <<= 1;
	for(int i = 0 ; i < n; i++){
		segTree[i + strIdx] = arr[i];
	}
	for (int i = strIdx - 1; i >= 1; i--) {
		segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
	}
}

void update(int idx, int val) {
	arr[idx] += val;
	int i = idx + strIdx;
	segTree[i] += val;
	i >>= 1;
	while (i >= 1) {
		segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
		i >>= 1;
	}
}

void findVal(int tar) {
	int currIdx = 1;
	while (currIdx < strIdx) {
		if (tar > segTree[currIdx << 1]) {
			tar -= segTree[currIdx << 1];
			currIdx = (currIdx << 1) + 1;
		}
		else {
			currIdx <<= 1;
		}
	}
	cout << currIdx - strIdx + 1 << "\n"; 
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	init();

	cin >> q;
	for (int i = 0; i < q; i++) {
		int inst;
		cin >> inst;
		if (inst == 1) {
			int idx, val;
			cin >> idx >> val;
			update(idx - 1, val);
		}
		if (inst == 2) {
			int tar;
			cin >> tar;
			findVal(tar);
		}
	}
}