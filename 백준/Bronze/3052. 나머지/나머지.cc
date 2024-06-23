#include <iostream>
using namespace std;

int arr[42];
int num, cnt;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 10; i++) {
		cin >> num;
		arr[num % 42]++;
	}

	for (int i = 0; i < 42; i++) {
		if (arr[i] > 0) cnt++;
	}
	cout << cnt;
}