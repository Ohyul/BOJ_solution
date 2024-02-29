#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, k, maxi, maxCnt;
int arr[10][10], visited[10][10];
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int cases, each_case;

void dfs(int row, int col, int cnt, int cut) {
	maxCnt = max(maxCnt, cnt);
	for (int i = 0; i < 4; i++) {
		int nextR = row + dr[i];
		int nextC = col + dc[i];
		if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
		if (visited[nextR][nextC] == 1) continue;
		if (arr[row][col] <= arr[nextR][nextC]) {
			if (cut == 1) continue;
			int diff = arr[nextR][nextC] - arr[row][col];
			if (diff >= k) continue;
			visited[nextR][nextC] = 1;
			int originalVal = arr[nextR][nextC];
			arr[nextR][nextC] = arr[row][col] - 1;
			dfs(nextR, nextC, cnt + 1, 1);
			arr[nextR][nextC] = originalVal;
			visited[nextR][nextC] = 0;
		}
		else {
			visited[nextR][nextC] = 1;
			dfs(nextR, nextC, cnt + 1, cut);
			visited[nextR][nextC] = 0;
		}
	}
}

int main() {
	cin >> cases;
	while (each_case++ < cases) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				maxi = max(maxi, arr[i][j]);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == maxi) {
					visited[i][j] = 1;
					dfs(i, j, 1, 0);
					visited[i][j] = 0;
				}
			}
		}
		cout << "#" << each_case << " " << maxCnt <<"\n";
		n = 0, k = 0, maxi = 0, maxCnt = 0;
	}
}
