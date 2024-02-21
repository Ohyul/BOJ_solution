#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Edge {
	int a, b, val;
};

bool compare(Edge& left, Edge& right) {
	return left.val < right.val;
}

vector <Edge> lines;

char univ[1010];
int arr[1010], n, m, cnt, val, flag;


int find(int tar) {
	if (tar == arr[tar]) return tar;
	int ret = find(arr[tar]);
	arr[tar] = ret;
	return ret;
}

void setUnion( int a, int b) {
	int t1 = find(a);
	int t2 = find(b);
	if (t1 == t2) return;
	if (t1 < t2) arr[t2] = t1;
	else arr[t1] = t2;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> univ[i];
		arr[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int a, b, val;
		cin >> a >> b >> val;
		if (univ[a - 1] == univ[b - 1]) continue;
		lines.push_back({ a - 1, b - 1, val });
	}

	sort(lines.begin(), lines.end(), compare);

	for (Edge line: lines) {
		if (find(line.a) == find(line.b)) continue;
		setUnion(line.a, line.b);

		cnt++;
		val += line.val;

		if (cnt == n - 1) {
			flag = 1;
			break;
		}
	}
	if (flag == 1) cout << val;
	else cout << "-1";
}