#include <iostream>

using namespace std;

long long n, m;
long long MIN = 1e9;

void recur(long long level, long long cnt) {
	if (level == m) {
		if (cnt < MIN) {
			MIN = cnt;
		}
		return;
	}
	if(level * 2 <= m) recur(level * 2, cnt + 1);
	if ((level * 10) +1 <= m) recur((level * 10) + 1, cnt + 1);
}


int main() {
	cin >> n >> m;
	recur(n, 1);
	if (MIN == 1e9) {
		cout << "-1";
	}
	else {
		cout << MIN;
	}
}