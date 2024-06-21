#include <iostream>
using namespace std;

string str;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> str;
	for (int i = 1; i <= str.length(); i++) cout << str[str.length() - i];
}
