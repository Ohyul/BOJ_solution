#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n, row, col;
	cin >> n >> row >> col;
	int idx = 0;
	while (n > 0) {
		if (row >= pow(2, n-1) ){
			if (col >= pow(2, n - 1)) {
				idx += 3 * pow(4, n - 1);
				row -= pow(2, n-1);
				col -= pow(2, n-1);
			}
			else {
				idx += 2 * pow(4, n - 1);
				row -= pow(2, n-1);
			}
		}
		else {
			if (col >= pow(2, n - 1)) {
				idx += 1 * pow(4, n - 1);
				col -= pow(2, n-1);
			}
			else {
				idx += 0;
			}
		}
		n--;
	}
	cout << idx;
}