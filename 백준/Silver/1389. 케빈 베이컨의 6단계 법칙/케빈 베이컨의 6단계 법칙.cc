#include <iostream>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int row = 0, col = 0;
	int arr[101][101] = { 0 };
	int result = 5000;
	int idx = 0;

	for (int i = 0; i < m;i++) {
		cin >> row >> col;
		arr[row][col] = arr[col][row] = 1;
	}

	for (int mid = 1; mid <= n; mid++) {
		for (int str = 1; str <= n; str++) {
			for (int end = 1; end <= n; end++) {
				if (str != end) {
					if (arr[str][mid] != 0 and arr[mid][end] != 0) {
						if (arr[str][end] == 0) {
							arr[str][end] = arr[str][mid] + arr[mid][end];
						}
						else {
							arr[str][end] = min(arr[str][end], arr[str][mid] + arr[mid][end]);
						}
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += arr[i][j];
		}
		if (result > sum) {
			result = sum;
			idx = i;
		}
	}

	cout << idx;
	return 0;
}