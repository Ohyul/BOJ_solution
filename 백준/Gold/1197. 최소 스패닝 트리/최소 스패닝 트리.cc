#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
	int a, b, val;
};

vector <Edge> lines;

bool compare(Edge& left, Edge& right) {
	return left.val < right.val;
}

int arr[10010], v, e, ans, cnt;


int find(int tar) {
	if (tar == arr[tar]) return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion(int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	if (t1 < t2) arr[t2] = t1;
	else arr[t1] = t2;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v >> e;

	for (int i = 1; i <= v; i++) {
		arr[i] = i;
	}

	for (int i = 0; i < e; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		lines.push_back({ a, b, val });
	}
	sort(lines.begin(), lines.end(), compare);

	for (Edge sel: lines) {
		if (find(sel.a) == find(sel.b)) continue;
		setUnion(sel.a, sel.b);

		ans += sel.val;
		cnt++;
		if (cnt == e - 1) break;
	}
	cout << ans;
}