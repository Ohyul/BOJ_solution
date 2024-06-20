#include <iostream>
using namespace std;

int row, col, colorNum;
int colors[10];
int map[15][15];
int dr[2] = { 0, 0 };
int dc[2] = { 1,-1 };
int dir;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> row >> col >> colorNum;
	for (int i = 0; i < colorNum; i++) cin >> colors[i];

	int idx = 1;
	int colorIdx = 0;
	int currR = 0, currC = 0;
	while (colorIdx <= colorNum) {
		map[currR][currC] = colorIdx;
		idx++;

		if (idx > colors[colorIdx]) {
			idx = 1;
			colorIdx++;
		}

		int nextR = currR + dr[dir];
		int nextC = currC + dc[dir];
		if (nextC >= col) {
			nextR = currR + 1;
			nextC = currC;
			dir = (dir + 1) % 2;
		}
		
		else if (nextC < 0) {
			nextR = currR + 1;
			nextC = currC;
			dir = (dir + 1) % 2;
		}

		currR = nextR;
		currC = nextC;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << map[i][j] + 1;
		}
		cout << "\n";
	}
}