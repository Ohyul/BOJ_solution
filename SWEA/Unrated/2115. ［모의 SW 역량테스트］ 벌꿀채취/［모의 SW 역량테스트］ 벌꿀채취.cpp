#include <iostream>
#include <algorithm>
using namespace std;

int n, m, c, ans;
int arr[12][12], sum[12][12];
int cases, each_case;
int maxi, maxi_row, maxi_col;

int findMax(int row, int col) {
	int poss = 1 << m, maxi = 0;

	for (int bitmask = 0; bitmask < poss; bitmask++) {
		int val = 0, cost = 0;

		for (int j = 0; j < m; j++) {
			if (bitmask & (1 << j)) {
				val += arr[row][col + j];
				if (val > c) break;
				cost += arr[row][col + j] * arr[row][col + j];
			}
		}
		if (val <= c) {
			maxi = max(maxi, cost);
		}
	}

	return maxi;
}


int main() {
	cin >> cases;
	each_case = 1;
	while (each_case <= cases) {
		cin >> n >> m >> c;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				sum[i][j] = findMax(i, j);
				if (sum[i][j] > maxi) {
					maxi = sum[i][j];
					maxi_row = i;
					maxi_col = j;
				}
			}
		}
		ans += maxi;
		for (int j = 0; j < n; j++) {
			sum[maxi_row][j] = 0;
		}

		maxi = 0, maxi_row = 0, maxi_col = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - m + 1; j++) {
				if (sum[i][j] > maxi) {
					maxi = sum[i][j];
					maxi_row = i;
					maxi_col = j;
				}
			}
		}
		ans += maxi;
		cout << "#" << each_case << " " << ans << "\n";
		ans = 0, maxi = 0, maxi_row = 0, maxi_col = 0;
		each_case++;
	}
}