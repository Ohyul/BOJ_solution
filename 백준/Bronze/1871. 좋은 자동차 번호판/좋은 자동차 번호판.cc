#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int n;
string str;
int first, second;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;

		first = 0, second = 0;

		first += (str[0] - 'A') * 26 * 26;
		first += (str[1] - 'A') * 26;
		first += (str[2] - 'A');

		second += (str[4] - '0') * 1000;
		second += (str[5] - '0') * 100;
		second += (str[6] - '0') * 10;
		second += (str[7] - '0');

		int diff = first - second;
		if (diff >= -100 && diff <= 100) cout << "nice\n";
		else cout << "not nice\n";
	}
}