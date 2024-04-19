#include <iostream>
#include <queue>
#include <algorithm>
#include <unordered_set>
typedef long long ll;
using namespace std;

struct Node {
	ll val, cnt;
};

queue <Node> q;
unordered_set<ll> s;
ll n;

int main() {
	cin >> n;

	s.insert(n);
	q.push({ n, 0 });
	while (!q.empty()) {
		Node curr = q.front();
		q.pop();

		if (curr.val == 1) {
			cout << curr.cnt;
			break;
		}

		if (curr.val % 3 == 0) {
			if (s.count(curr.val / 3) == 0) {
				s.insert(curr.val / 3);
				q.push({ curr.val / 3, curr.cnt + 1 });
			}
		}
		if (curr.val % 2 == 0) {
			if (s.count(curr.val / 2) == 0) {
				s.insert(curr.val / 2);
				q.push({curr.val / 2, curr.cnt + 1 });
			}
		}
		if (s.count(curr.val - 1) == 0) {
			s.insert(curr.val - 1);
			q.push({curr.val - 1, curr.cnt + 1 });
		}
	}
}