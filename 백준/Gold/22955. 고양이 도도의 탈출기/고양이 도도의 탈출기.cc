#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
	int row, col, val;

	bool operator<(const Node& r) const {
		if (val < r.val) return false;
		if (val > r.val) return true;
		return false;
	}
};

priority_queue <Node> q; 
char arr[1010][1010];
int n, m;
int dist[1010][1010];

int dr[4] = {  0, 0 };
int dc[4] = { 1, -1 };
int mini = INT_MAX;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dist[i][j] = INT_MAX;
			if (arr[i][j] == 'C') {
				q.push({ i, j, 0 });
				dist[i][j] = 0;
			}
		}
	}

	while (!q.empty()) {
		Node curr = q.top();
		q.pop();

		int row = curr.row;
		int col = curr.col;
		int val = curr.val;

		if (arr[row][col] == 'E') {
			mini = min(mini, val);
			continue;
		}

		//X일때 >> 무조건 떨어짐
		if (arr[row][col] == 'X') {
			int nextR = row + 1;
			int nextC = col;
			int nextVal = val + 10;
			while (arr[nextR][nextC] == 'X') {
				nextR++;
			}
			if (dist[nextR][nextC] > nextVal && arr[nextR][nextC] != 'D') {
				dist[nextR][nextC] = nextVal;
				q.push({ nextR, nextC, nextVal });
			}
			continue;
		}

		//사다리일 때 >> 선택
		if (row - 1 >= 0 && arr[row][col] == 'L') {
			int nextR = row - 1;
			int nextC = col;
			int nextVal = val + 5;
			if (dist[nextR][nextC] > nextVal && arr[nextR][nextC] != 'D') {
				dist[nextR][nextC] = nextVal;
				q.push({ nextR, nextC, nextVal });
			}
		}
		if (row + 1 < n && arr[row + 1][col] == 'L') {
			int nextR = row + 1;
			int nextC = col;
			int nextVal = val + 5;
			if (dist[nextR][nextC] > nextVal && arr[nextR][nextC] != 'D') {
				dist[nextR][nextC] = nextVal;
				q.push({ nextR, nextC, nextVal });
			}
		}
		
		//수평이동
		for (int i = 0; i < 2; i++) {
			int nextR = row + dr[i];
			int nextC = col + dc[i];
			int nextVal = val + 1;
			if (nextC < 0 || nextC >= m) continue;
			if (arr[nextR][nextC] == 'D') continue;
			if (dist[nextR][nextC] <= nextVal) continue;
			dist[nextR][nextC] = nextVal;
			q.push({ nextR, nextC, nextVal });
		}
	}

	if (mini == INT_MAX) {
		cout << "dodo sad";
	}
	else {
		cout << mini;
	}
}