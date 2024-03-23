#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

struct Node {
	int row, col, val, visited;

	bool operator< (const Node& r) const {
		if (val < r.val) return false;
		if (val > r.val) return true;
		return false;
	}
};

int n, m, k;
priority_queue <Node> q;
int arr[1010][1010], visited[1010][1010];

int dr[4] = { 1, -1, 0 ,0 };
int dc[4] = { 0, 0, 1, -1 };


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		for (int j = 0; j < m; j++) {
			arr[i][j] = input[j] - '0';
		}
	}

	memset(visited, -1, sizeof(visited));

	visited[0][0] = 0;
	q.push({ 0, 0, 1, 0 });

	while (!q.empty()) {
		Node curr = q.top();
		q.pop();

		if (curr.row == n - 1 && curr.col == m - 1) {
			cout << curr.val;
			q = {};
			return 0;
		}

		for (int i = 0; i < 4; i++) {
			int nextR = curr.row + dr[i];
			int nextC = curr.col + dc[i];
			int nextV = curr.val + 1;
			int nextVisited = curr.visited;
			if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) continue;
			if (arr[nextR][nextC] == 1) nextVisited += 1;
			if (nextVisited > k) continue;
			if (visited[nextR][nextC] != -1 && visited[nextR][nextC] <= nextVisited) continue;
			visited[nextR][nextC] = nextVisited;
			q.push({ nextR, nextC, nextV, nextVisited });
		}
	}
	cout << "-1";
}
