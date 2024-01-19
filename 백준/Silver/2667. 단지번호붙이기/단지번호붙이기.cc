#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

pair<int, int> p;

int arr[25][25];
bool visited[25][25];

int dr[4] = {0,0,1,-1};
int dc[4] = {1,-1,0,0};
queue<pair<int, int>> q;
vector<int> v;
int n;
string str;



int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}

	for (int i = 0; i < n;i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 1 && visited[i][j] == 0) {
				visited[i][j] = 1;
				int cnt = 1;
				q.push(make_pair(i,j));
				while (!q.empty()) {
					int row, col;
					row = q.front().first;
					col = q.front().second;
					q.pop();
					for (int k = 0; k < 4; k++) {
						if (row + dr[k] >= 0 && row + dr[k] < 25 && col + dc[k] >= 0 && col + dc[k] < 25) {
							if (visited[row + dr[k]][col + dc[k]] == 0 && arr[row+dr[k]][col+dc[k]] == 1) {
								q.push(make_pair(row+dr[k], col+dc[k]));
								visited[row + dr[k]][col + dc[k]] = 1;
								cnt++;
							}
						}
					}
				}
				v.push_back(cnt);
			}
		}
	}
	cout << v.size() << endl;
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}
