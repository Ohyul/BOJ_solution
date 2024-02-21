#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node {
	int row, col, val;
};

queue <Node> q;

struct Edge {
	int from, to, val;
};

bool compare(Edge& left, Edge& right) {
	return left.val < right.val;
}

vector <Edge> bridges;

int r, c, map[13][13], visited[13][13], arr[8], idx = 1;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };
int cnt, val, flag;

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

void bfs(int row, int col, int idx) {
	visited[row][col] = 1;
	map[row][col] = idx;
	q.push({ row, col });
	while (!q.empty()) {
		int currR = q.front().row;
		int currC = q.front().col;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextR = currR + dr[i];
			int nextC = currC + dc[i];
			if (nextR < 0 || nextR >= r || nextC < 0 || nextC >= c) continue;
			if (map[nextR][nextC] == 0 || visited[nextR][nextC] == 1) continue;
			visited[nextR][nextC] = 1;
			map[nextR][nextC] = idx;
			q.push({ nextR, nextC });
		}
	}
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] != 0 && visited[i][j] == 0) {
				bfs(i, j, idx);
				idx++;
			}
		}
	}


	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 0) continue;
			int currIdx = map[i][j];
			for (int k = 0; k < 4; k++) {
				int nextR = i + dr[k];
				int nextC = j + dc[k];
				if (nextR < 0 || nextR >= r || nextC < 0 || nextC > c) continue;
				if (map[nextR][nextC] == currIdx) continue;
				int dist = 1;
				while (true) {
					if (nextR < 0 || nextR >= r || nextC < 0 || nextC > c) break;
					if (map[nextR][nextC] == currIdx) break;
					if (map[nextR][nextC] != 0) {
						if(dist - 1 >= 2) bridges.push_back({ currIdx, map[nextR][nextC], dist -1 });
						break;
					}
					nextR += dr[k];
					nextC += dc[k];
					dist++;
				}
			}
		} 
	}


	for (int i = 0; i < 8; i++) {
		arr[i] = i;
	}

	sort(bridges.begin(), bridges.end(), compare);

	for (Edge bridge : bridges) {
		if(find(bridge.from) == find(bridge.to)) continue;
		setUnion(bridge.from, bridge.to);

		val += bridge.val;
		cnt++;

		if (cnt == idx - 2) {
			flag = 1;
			break;
		}
	}

	if (flag == 1) cout << val;
	else cout << "-1";
}