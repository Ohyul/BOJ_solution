#include <iostream>
#include <algorithm>
#include <climits>
#include <queue>
using namespace std;

struct Node {
    int row, col, val;
};

queue <Node> q;

int arr[1010][1010], visited[1010][1010];
int n, m, k;
int ans = INT_MAX;
int maxi;
int dr[4] = { 1, -1, 0, 0 };
int dc[4] = { 0, 0, 1, -1 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            maxi = max(maxi, arr[i][j]);
        }
    }
    int left = 0, right = maxi;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;

        //Visited 초기화
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                visited[i][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            if (arr[0][i] <= mid) {
                visited[0][i] = 1;
                cnt++;
                q.push({ 0, i });
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i][0] <= mid && visited[i][0] == 0) {
                visited[i][0] = 1;
                cnt++;
                q.push({ i, 0 });
            }
            if (arr[i][m-1] <= mid && visited[i][m-1] == 0) {
                visited[i][m-1] = 1;
                cnt++;
                q.push({ i, m-1 });
            }
        }


        while (!q.empty()) {
            Node curr = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nextR = curr.row + dr[i];
                int nextC = curr.col + dc[i];
                if (nextR < 0 || nextR >= n || nextC < 0 || nextC >= m) continue;
                if (arr[nextR][nextC] > mid || visited[nextR][nextC] == 1) continue;
                cnt++;
                visited[nextR][nextC] = 1;
                q.push({ nextR,nextC });
            }
        }


        if (cnt >= k) {
            right = mid - 1;
            ans = mid;
        }
        else {
            left = mid + 1;
        }
    }
    cout << ans;
}
