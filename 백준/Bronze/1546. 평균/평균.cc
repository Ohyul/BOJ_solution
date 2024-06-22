#include <iostream>
using namespace std;

int n, maxi;
int arr[1010];
double ret;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > maxi) maxi = arr[i];
		ret += arr[i];
	}
	ret = (ret / maxi * 100) / n;

	cout << fixed;
	cout.precision(6);

	cout << ret;
}