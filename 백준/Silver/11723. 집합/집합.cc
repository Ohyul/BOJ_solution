#include <iostream>
using namespace std;

int s[21] = { 0, };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		int x = 0;
		cin >> str;
		if (str == "add") {
			cin >> x;
			s[x] = 1;
		}
		else if (str == "remove") {
			cin >> x;
			s[x] = 0;
		}
		else if (str == "check") {
			cin >> x;
			if (s[x] == 1) {
				cout << "1" << "\n";
			}
			else {
				cout << "0" << "\n";
			}
		}
		else if (str == "toggle") {
			cin >> x;
			s[x] = (s[x] + 1) % 2;
		}
		else if (str == "all") {
			for (int i = 1; i <= 20; i++) {
				s[i] = 1;
			}
		}
		else if (str == "empty") {
			for (int i = 1; i <= 20; i++) {
				s[i] = 0;
			}
		}
	}
}
