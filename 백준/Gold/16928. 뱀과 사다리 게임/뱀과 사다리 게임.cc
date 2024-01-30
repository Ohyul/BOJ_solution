#include <iostream>
#include <queue>
using namespace std;

struct ladder_snake {
	int start;
	int end;
};

struct Game {
	int place;
	int count;
};

ladder_snake la_sn[30];

int used[110];
int n, m;
int cnt;
int mini = 1e9;
queue <Game> q;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		int str, end;
		cin >> str >> end;
		la_sn[i] = { str, end };
	}
	used[1] = 1;
	q.push({ 1, 0 });
	int iter_flag = 1;
	while (!q.empty() && iter_flag == 1) {
		int nowPlace = q.front().place;
		int nowCount = q.front().count;
		q.pop();
		if (nowPlace == 100) {
			mini = min(nowCount, mini);
			iter_flag = 0;
		}
		for (int i = 0; i < n+m; i++) {
			if (nowPlace == la_sn[i].start ) {
				nowPlace = la_sn[i].end;
			}
		}
		for (int i = 6; i >= 1; i--) {
			if (used[nowPlace + i] == 1) continue;
			used[nowPlace + i] = 1;
			q.push({ nowPlace + i, nowCount + 1 });
		}

	}
	cout << mini;
}