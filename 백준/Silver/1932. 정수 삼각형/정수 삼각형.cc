#include <iostream>

using namespace std;

int arr[500][500];
int dp[500][500];
int n;
int sum = 0;


int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		dp[n - 1][i] = arr[n - 1][i];
	}
	for (int i = n-2; i >= 0 ; i--) {
		for (int j = 0; j <= i; j++) {
			dp[i][j] = max(dp[i + 1][j] + arr[i][j], dp[i + 1][j + 1] + arr[i][j]);
		}
	}

	cout << dp[0][0];
}