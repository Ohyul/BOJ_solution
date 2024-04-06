#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define INF 1e9
using namespace std;

struct node {
    int x, y, dir, cnt;

    node(int _x, int _y, int _dir, int _cnt) : x(_x), y(_y), dir(_dir), cnt(_cnt) {}

    bool operator > (const node& n) const {
        return cnt > n.cnt;
    }
};

char map[110][110];
int dist[110][110][4];
vector<node> c;
int n, m;


int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int changeDir(int dir, int i) {
    if (i == 1) {
        if (dir == 0 || dir == 1) return 2;
        else return 0;
    }
    else {
        if (dir == 0 || dir == 1) return 3;
        else return 1;
    }
}

void dijkstra() {
    priority_queue<node, vector<node>, greater<node>> pq;

    int x = c[0].x;
    int y = c[0].y;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (map[nx][ny] == '*') continue;

        pq.push(node(x, y, i, 0));
        dist[x][y][i] = 0;
    }

    while (!pq.empty()) {
        int x = pq.top().x;
        int y = pq.top().y;
        int dir = pq.top().dir;
        int cnt = pq.top().cnt;
        pq.pop();

        if (x == c[1].x && y == c[1].y) {
            cout << cnt << "\n";
            return;
        }

        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
        if (map[nx][ny] == '*') continue;

        if (map[nx][ny] == '.') {
            for (int j = 1; j <= 2; j++) {
                int nd = changeDir(dir, j);

                if (dist[nx][ny][nd] > dist[x][y][dir] + 1) {
                    dist[nx][ny][nd] = dist[x][y][dir] + 1;
                    pq.push(node(nx, ny, nd, cnt + 1));
                }
            }
        }

        if (dist[nx][ny][dir] > dist[x][y][dir]) {
            dist[nx][ny][dir] = dist[x][y][dir];
            pq.push(node(nx, ny, dir, cnt));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'C') c.emplace_back(i, j, 0, 0);

            for (int k = 0; k < 4; k++) {
                dist[i][j][k] = INF;
            }
        }
    }

    dijkstra();
}
