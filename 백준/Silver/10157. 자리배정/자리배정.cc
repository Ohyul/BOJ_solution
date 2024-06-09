#include <iostream>
using namespace std;

int col, row, tar;
int map[1010][1010];

int dir;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
 
int main() {
	cin >> col >> row >> tar;

	int currR = row;
	int currC = 1;
	int num = 1;

	if (tar > row * col) {
		cout << "0";
		return 0;
	}

	while (true) {
		map[currR][currC] = num++;

		if (num > row * col + 1) break;

		if (tar + 1 == num) {
			cout << currC << " " << row - currR + 1 << "\n";
		}

		currR += dr[dir];
		currC += dc[dir];

		if (currR < 1 || currR > row || currC < 1 || currC > col || map[currR][currC] != 0) {
			currR -= dr[dir];
			currC -= dc[dir];
			dir = (dir + 1) % 4;

			currR += dr[dir];
			currC += dc[dir];
		}
	}
}