#include <iostream>
#include <queue>
using namespace std;

struct Node {
	char val;
	int row;
	int col;
};
int dr[4] = { 1,-1,0,0 };
int dc[4] = { 0,0,1,-1 };
queue <Node> q;
int rgb;
char arr[111][111];
bool used[111][111];
int n;

void bfs(Node node) {
	char start;
	if (node.val == 'R') start = 'R';
	if (node.val == 'G') start = 'G';
	if (node.val == 'B') start = 'B';
	rgb++;
	used[node.row][node.col] = 1;
	q.push({ start, node.row, node.col });
	while (!q.empty()) {
		char c = q.front().val;
		int nowRow = q.front().row;
		int nowCol = q.front().col;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextRow = nowRow + dr[i];
			int nextCol = nowCol + dc[i];
			if (used[nextRow][nextCol] == 1) continue;
			if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n) continue;
			if (arr[nextRow][nextCol] == start) {
				used[nextRow][nextCol] = 1;
				q.push({ arr[nextRow][nextCol], nextRow, nextCol});
			}
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j] == 0) {
				bfs({ arr[i][j], i, j });
			}
		}
	}
	cout << rgb << " ";
	rgb = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			used[i][j] = 0;
			if (arr[i][j] == 'G') arr[i][j] = 'R';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (used[i][j] == 0) {
				bfs({ arr[i][j], i, j });
			}
		}
	}
	cout << rgb << " ";

}