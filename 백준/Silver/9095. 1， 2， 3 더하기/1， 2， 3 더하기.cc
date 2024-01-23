#include <iostream>

using namespace std;

int cnt;

void cases(int n) {
	if (n == 1) {
		cnt++;
		return;
	}
	if (n == 2) {
		cnt++;
		cases(n - 1);
	}
	if (n == 3) {
		cnt++;
		cases(n - 2);
		cases(n - 1);
	}
	if (n > 3) {
		cases(n - 3);
		cases(n - 2);
		cases(n - 1);
	}
}

int main() {
	int t;
	cin >> t;
	while (t > 0) {
		int n;
		cin >> n;
		cnt = 0;
		cases(n);
		cout << cnt << "\n";
		t--;
	}
}