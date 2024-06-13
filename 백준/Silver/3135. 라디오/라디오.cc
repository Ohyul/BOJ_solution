#include <iostream>
#include <queue>
using namespace std;

struct herz {
	int val, cnt;
};

queue<herz> q;
int a, b;
int n;
int arr[1010], visited[1010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> a >> b >> n;

	visited[a] = 1;
	q.push({ a, 0 });

	for (int i = 0; i < n; i++) {
		int fav;
		cin >> fav;
		visited[fav] = 1;
		q.push({ fav, 1 });
	}

	while (!q.empty()) {
		herz curr = q.front();
		q.pop();

		if (curr.val == b) {
			cout << curr.cnt;
			break;
		}

		if(curr.val > 1 && visited[curr.val - 1] == 0){
			visited[curr.val - 1] = 1;
			q.push({ curr.val - 1, curr.cnt + 1 });
		}

		if (curr.val < 1000 && visited[curr.val + 1] == 0) {
			visited[curr.val + 1] = 1;
			q.push({ curr.val + 1, curr.cnt + 1 });
		}
	}
}