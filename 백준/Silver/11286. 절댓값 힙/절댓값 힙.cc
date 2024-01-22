#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct cmp {
	bool operator()(int a, int b) {
		if (abs(a) == abs(b)) {
			return a > b;
		}
		return abs(a) > abs(b);
	}
};

vector<int> v;
priority_queue<int, vector<int>, cmp> q;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int op;
		cin >> op;
		if (op == 0) {
			if (q.empty()) {
				cout << "0" << endl;
			}
			else {
				cout << q.top() << endl;
				q.pop();
			}
		}
		else {
			q.push(op);
		}
	}
}