#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;

ll arr[2000100];
int n;
ll maxiNum, maxi;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll a;
		cin >> a;
		arr[a]++;
		maxi = max(maxi, a);
	}

	for (ll i = 1; i <= maxi; i++) {
		ll cnt = 0;
		for (ll j = i; j <= maxi; j += i) {
			cnt += arr[j];
		}
		if (cnt >= 2) {
			maxiNum = max(maxiNum, cnt * i);
		}
	}
	cout << maxiNum << "\n";
}
