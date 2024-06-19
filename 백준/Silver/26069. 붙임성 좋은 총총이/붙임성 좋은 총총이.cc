#include <iostream>
#include <cstring>
#include <string>
#include <unordered_set>
using namespace std;

int n;
string str1, str2;
unordered_set <string> us;
int cnt;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	us.insert("ChongChong");
	cnt = 1;

	for (int i = 0; i < n; i++) {
		cin >> str1 >> str2;
		if (str1 == "ChongChong" && us.count(str2) == 0) {
			cnt++;
			us.insert(str2);
		}
		else if (str2 == "ChongChong" && us.count(str1) == 0) {
			cnt++;
			us.insert(str1);
		}
		else if (us.count(str1) == 1 && us.count(str2) == 0) {
			cnt++;
			us.insert(str2);
		}
		else if (us.count(str2) == 1 && us.count(str1) == 0) {
			cnt++;
			us.insert(str1);
		}
	}
	cout << cnt;
}