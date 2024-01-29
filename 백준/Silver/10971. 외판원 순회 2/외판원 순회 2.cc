#include <iostream>

using namespace std;

bool used[12];
long long arr[12][12];
long long n;
long long mini = 21e19;

void dfs(long long level, long long sum, int nowPoint) {
    if (level == n - 1) {
        if (arr[nowPoint][0] == 0) return;
        sum += arr[nowPoint][0];
        mini = min(mini, sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == 1 || arr[nowPoint][i] == 0) continue;
        used[i] = 1;
        dfs(level + 1, sum + arr[nowPoint][i], i);
        used[i] = 0;
    }
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
    used[0] = 1;
	dfs(0, 0, 0);

	cout << mini;
}