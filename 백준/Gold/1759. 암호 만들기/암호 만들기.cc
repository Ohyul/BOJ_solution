#include <iostream>
using namespace std;

int n, m;
int alpha[26], visited[26];

void dfs(int now, int cnt, string curr) {
	if (cnt == n) {
		int consonant = 0;
		int vowel = 0;
		for (int i = 0; i < n; i++) {
			if (curr[i] - 'a' == 0 || curr[i] - 'a' == 4 || curr[i] - 'a' == 8 || curr[i] - 'a' == 14 || curr[i] - 'a' == 20) {
				vowel++;
			}
			else {
				consonant++;
			}
		}
		if (vowel < 1 || consonant < 2) return;
		cout << curr << "\n";
		return;
	}

	for (int i = now; i < 26; i++) {
		if (alpha[i] == 1 && visited[i] == 0) {
			visited[i] = 1;
			curr.push_back(char(i + 'a'));
			dfs(i, cnt + 1, curr);
			visited[i] = 0;
			curr.pop_back();
		}
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char al;
		cin >> al;
		alpha[al - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (alpha[i] == 1) {
			visited[i] = 1;
			string out = "";
			out.push_back(char(i + 'a'));
			dfs(i, 1, out);
			visited[i] = 0;
			out.pop_back();
		}
	}
}