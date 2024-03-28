#include <iostream>
#include <climits>
using namespace std;
struct Node {
	int mini, maxi;
};

int arr[180010];
Node segTree[180010 * 4];
int n, q;
int strIdx;

void init() {
    strIdx = 1;
    while (strIdx < n) {
        strIdx *= 2;
    }
    for (int i = 0; i < n; i++) {
        segTree[i + strIdx].mini = arr[i];
        segTree[i + strIdx].maxi = arr[i];
    }
    for (int i = n + strIdx; i < strIdx * 2; i++) {
        segTree[i].mini = INT_MAX;
        segTree[i].maxi = INT_MIN;
    }
    for (int i = strIdx - 1; i != 0; i--) { 
        segTree[i].mini = min(segTree[i << 1].mini, segTree[i << 1 | 1].mini);
        segTree[i].maxi = max(segTree[i << 1].maxi, segTree[i << 1 | 1].maxi);
    }
}

void query(int from, int to) {
	int mini = INT_MAX, maxi = INT_MIN;
	for (from += strIdx, to += strIdx + 1; from < to; from >>= 1, to >>= 1) {
		if (from & 1) {
			mini = min(mini, segTree[from].mini);
			maxi = max(maxi, segTree[from].maxi);
			from++;
		}
		if (to & 1) {
			to--;
			mini = min(mini, segTree[to].mini);
			maxi = max(maxi, segTree[to].maxi);
		}
	}
	cout << maxi - mini << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init();

	for (int i = 0; i < q; i++) {
		int from, to;
		cin >> from >> to;
		query(from - 1, to - 1);
	}

}