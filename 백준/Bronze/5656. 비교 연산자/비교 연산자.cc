#include <iostream>
using namespace std;

int a, b, flag, tc = 1;
string op;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		cin >> a >> op >> b;

		if (op == "E") break;

		if (op == ">") {
			if (a > b) flag = 1;
			else flag = 0;
		}

		else if (op == ">=") {
			if (a >= b) flag = 1;
			else flag = 0;
		}

		else if (op == "<") {
			if (a < b) flag = 1;
			else flag = 0;
		}

		else if (op == "<=") {
			if (a <= b) flag = 1;
			else flag = 0;
		}

		else if (op == "==") {
			if (a == b) flag = 1;
			else flag = 0;
		}

		else if (op == "!=") {
			if (a != b) flag = 1;
			else flag = 0;
		}

		if (flag == 1) cout << "Case " << tc++ << ": true\n";
		else cout << "Case " << tc++ << ": false\n";
	}
}