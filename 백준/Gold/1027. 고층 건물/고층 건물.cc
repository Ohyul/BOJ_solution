#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

int N, ans;

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0);

	cin >> N;

	vector<int> building(N);
	vector<int> cnt(N, 0);
	for (int i = 0; i < N; i++)
		cin >> building[i];

	for (int i = 0; i < N; i++) {
		double maxi = INT_MIN;
		for (int j = i + 1; j < N; j++) {
			double level = (double)(building[j] - building[i]) / (j - i);
			if (level > maxi) {
				cnt[i]++;
				cnt[j]++;
				maxi = level;
			}
		}
	}

	for (auto el : cnt)
		ans = max(ans, el);

	cout << ans;
}