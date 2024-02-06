#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int row, col, val, wall;

	bool operator<(const Node& right) const {
		if (wall < right.wall) return false;
		if (wall > right.wall) return true;
		return false;
	}
};

priority_queue <Node> q;

int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };

int arr[110][110];
int used[110][110];
int ans[110][110];
int n, m;

int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string in;
		cin >> in;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = in[j - 1] - '0';
			ans[i][j] = 1e9;
		}
	}

	ans[1][1] = 0;
	used[1][1] = 1;
	q.push({ 1,1,arr[1][1], 0 });
	while (!q.empty()) {
		Node now = q.top();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextRow = now.row + dr[i];
			int nextCol = now.col + dc[i];
			if (nextRow < 1 || nextRow > n || nextCol < 1 || nextCol > m) continue;
			if (used[nextRow][nextCol] == 1) continue;
			int nextVal = arr[nextRow][nextCol];
			int nextWall = (nextVal == 1) ? now.wall + 1 : now.wall;
			if (ans[nextRow][nextCol] > nextWall) {
				used[nextRow][nextCol] = 1;
				ans[nextRow][nextCol] = min(ans[nextRow][nextCol], nextWall);
				q.push({ nextRow, nextCol, arr[nextRow][nextCol], nextWall });
			}
		}
	}

	cout << ans[n][m];

}