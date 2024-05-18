#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<>> minHeap;
priority_queue<int> maxHeap;

int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int curr;
		cin >> curr;

		if (i == 0) {
			maxHeap.push(curr);
		}
		else if (i == 1) {
			if (curr > maxHeap.top()) {
				minHeap.push({ curr });
			}
			else {
				minHeap.push({ maxHeap.top() });
				maxHeap.pop();
				maxHeap.push({ curr });
			}
		}
		else {
			maxHeap.push(curr);
			if (maxHeap.top() > minHeap.top()) {
				maxHeap.pop();
				minHeap.push({ curr });
				if (minHeap.size() > maxHeap.size()) {
					maxHeap.push(minHeap.top());
					minHeap.pop();
				}
			}
			if (maxHeap.size() - minHeap.size() > 1) {
				minHeap.push({ maxHeap.top() });
				maxHeap.pop();
			}
		}
		cout << maxHeap.top() << "\n";
	}
}