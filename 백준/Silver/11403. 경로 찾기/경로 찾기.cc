#include <iostream>

using namespace std;

int arr[100][100];

int main() {
	int n;
	cin >> n;
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cin >> arr[row][col];
		}
	}

	for (int mid = 0; mid < n; mid++) {
		for (int str = 0; str < n; str++) {
			for (int end = 0; end < n; end++) {
				if (arr[str][end] == 0 && arr[str][mid] == 1 && arr[mid][end] == 1) {
					arr[str][end] = 1;
				}
			}
		}
	}
	for (int row = 0; row < n; row++) {
		for (int col = 0; col < n; col++) {
			cout << arr[row][col] << " ";
		}
		cout << endl;
	}

}