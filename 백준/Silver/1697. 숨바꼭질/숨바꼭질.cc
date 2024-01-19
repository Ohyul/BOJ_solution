#include <iostream>
#include <queue>

using namespace std;

int min = 1e9;
int n, k;
int arr[100001];
bool visited[100001];


void bfs() {
	queue<int> q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int current = q.front();
		q.pop();
		if (current == k) {
			return;
		}
		if (current - 1 >= 0) {
			if (visited[current - 1] == 0) {
				arr[current - 1] = arr[current] + 1;
				q.push(current - 1);
				visited[current - 1] = 1;
			}
		}
		if (current + 1 <= 100000) {
			if (visited[current + 1] == 0) {
				arr[current + 1] = arr[current] + 1;
				q.push(current + 1);
				visited[current + 1] = 1;
			}
		}
		if (current * 2 <= 100000) {
			if (visited[current * 2] == 0) {
				arr[current * 2] = arr[current] + 1;
				q.push(current * 2);
				visited[current * 2] = 1;
			}
		}
	}
}


int main() {
	cin >> n >> k;

	bfs();
	cout << arr[k];
	return 0;
}

