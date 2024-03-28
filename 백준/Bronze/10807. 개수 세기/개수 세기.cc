#include <iostream>
using namespace std;

int arr[500];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int idx;
		cin >> idx;
		idx += 250;
		arr[idx]++;
	}
	int tar;
	cin >> tar;
	tar += 250;
	cout << arr[tar];
}