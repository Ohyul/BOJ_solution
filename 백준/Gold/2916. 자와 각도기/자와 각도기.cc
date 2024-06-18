#include <iostream>
using namespace std;

int n, k;
int angle[361][15], arr[15], circle[361];
int tar;

void calc(int val, int pos) {
	if (pos == n) return;
	if (angle[val][pos]) return;
	angle[val][pos] = 1;
	circle[val] = 1;
	int nach = (val + arr[pos] + 360) % 360;
	if (!angle[nach][pos]) calc(nach, pos);
	nach = (val - arr[pos] + 360) % 360;
	if (!angle[nach][pos]) calc(nach, pos);
	calc(val, pos + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	calc(0, 0);
	for (int i = 0; i < k; i++) {
		cin >> tar;
		if (circle[tar] == 1) cout << "YES\n";
		else cout << "NO\n";
	}
}