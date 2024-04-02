#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct Node {
	int row, col;
	char val;
};

Node arr[2010][2010];
int n;
deque <Node> dq;

int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j].val;
			if (arr[i][j].val == 'X') {
				dq.push_front({ i, j, arr[i][j].val });
			}
			if (arr[i][j].val == 'O') {
				dq.push_back({ i, j, arr[i][j].val });
			}
		}
	}

	while (dq.front().val == 'X') {
		Node curr = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nextR = curr.row + dr[i];
			int nextC = curr.col + dc[i];
			if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
			if (arr[nextR][nextC].val == 'X' || arr[nextR][nextC].val == 'O') continue;
			while (!(nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) && !(arr[nextR][nextC].val == 'X' || arr[nextR][nextC].val == 'O')) {
				arr[nextR][nextC].val = '1';
				nextR += dr[i];
				nextC += dc[i];
			}
		}
	}


	while (!dq.empty()) {
		Node curr = dq.front();
		dq.pop_front();

		for (int i = 0; i < 4; i++) {
			int nextR = curr.row + dr[i];
			int nextC = curr.col + dc[i];
			if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
			if (arr[nextR][nextC].val == 'X' || arr[nextR][nextC].val == 'O') continue;
			while (!(nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) && !(arr[nextR][nextC].val == 'X' || arr[nextR][nextC].val == 'O')) {
				arr[nextR][nextC].val = '.';
				nextR += dr[i];
				nextC += dc[i];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j].val == '1') {
				arr[i][j].val = 'B';
			}
			cout << arr[i][j].val;
		}
		cout << "\n";
	}
}
