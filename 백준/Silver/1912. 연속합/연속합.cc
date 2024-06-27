#include <iostream>
#include <algorithm>
using namespace std;

int arr[100010], dp[100010], n, ans;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	ans = arr[0];
	dp[0] = arr[0];

	for (int i = 1; i < n; ++i) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(dp[i], ans);
	}

	cout << ans;
}