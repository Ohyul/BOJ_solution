#include <iostream>
#include <queue>
#include <climits>
using namespace std;

struct Node {
    int row, col;
};

queue <Node> q;

int n;
int arr[110][110], visited[110][110][110];
int mini = INT_MAX, maxi = INT_MIN; 
int ans = 1;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            mini = min(mini, arr[i][j]);
            maxi = max(maxi, arr[i][j]);
        }
    }

    for (int i = mini; i <= maxi; i++) {
        int tmpCnt = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (arr[r][c] > i && visited[r][c][i] == 0) { 
                    visited[r][c][i] = 1; 
                    tmpCnt++;
                    q.push({ r, c });
                    while (!q.empty()) {
                        Node curr = q.front();
                        q.pop();

                        for (int j = 0; j < 4; j++) { 
                            int nextR = curr.row + dr[j];
                            int nextC = curr.col + dc[j];
                            if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= n) continue;
                            if (visited[nextR][nextC][i] == 1 || arr[nextR][nextC] <= i) continue; 
                            visited[nextR][nextC][i] = 1; 
                            q.push({ nextR, nextC });
                        }
                    }
                }
            }
        }
        ans = max(ans, tmpCnt);
    }
    cout << ans;
}
