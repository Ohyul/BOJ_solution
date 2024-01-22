#include <iostream>

using namespace std;


int main() {
	int cases;
	cin >> cases;
	while (cases > 0) {
		int n;
		cin >> n;
		if (n > 32) {
			string str[100000];
			for (int i = 0; i < n; i++) {
				cin >> str[i];
			}
			cout << "0" << endl;
		}
		else {
			string str[32];
			int min_ = 1e9;
			for (int i = 0; i < n; i++) {
				cin >> str[i];
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) {
						int temp_diff = 0;
						if (i != j && j != k && k != i) {
							for (int mbti = 0; mbti < 4; mbti++) {
								if (str[i][mbti] != str[j][mbti]) {
									temp_diff++;
								}
								if (str[j][mbti] != str[k][mbti]) {
									temp_diff++;
								}
								if (str[k][mbti] != str[i][mbti]) {
									temp_diff++;
								}
							}
							min_ = min(min_, temp_diff);
						}
					}
				}
			}
			cout << min_ << endl;
		}
		cases--;
	}
}