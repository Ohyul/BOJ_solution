#include <iostream>

using namespace std;

int arr[129][129];
int white = 0, blue = 0;

void wb_check(int n, int y, int x) {
    if (n == 1) {
        if (arr[y][x] == 1) {
            blue++;
        } else {
            white++;
        }
        return;
    }
    int swt = 1;
    int half = n / 2;
    for (int i = y; i < y + n; i++) {
        if (swt == 0) { break; }
        for (int j = x; j < x + n; j++) {
            if (swt == 0) { break; }
            if (arr[y][x] != arr[i][j]) {
                wb_check(half, y, x);
                wb_check(half, y + half, x);
                wb_check(half, y, x + half);
                wb_check(half, y + half, x + half);
                swt = 0;
            }
        }
    }
    if (swt == 1) {
        if (arr[y][x] == 1) {
            blue++;
        } else {
            white++;
        }
    }
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	wb_check(n, 1, 1);
	cout << white << "\n" << blue;
}