#include <iostream>
using namespace std;

int n, cnt;

void solution(int n, int from, int via, int to) {
	if (n >= 1) {
		solution(n - 1, from, to, via);
		cout << from << " " << to << '\n';
		solution(n - 1, via, from, to);
	}
}

int main(void) {
	ios_base::sync_with_stdio(0);	
	cin.tie(0); 
	cout.tie(0);

	cin >> n;
	cnt = 1;

	for (int i = 0; i < n; i++) {
		cnt <<= 1;
	}

	cnt--;

	cout << cnt << '\n';

	solution(n, 1, 2, 3);
}