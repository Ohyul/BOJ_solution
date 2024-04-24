#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <climits>
#define INF INT_MAX
using namespace std;

int t, n, m;
int dist[30];
int path[30];
vector<pair<int, int>> line[30];
vector<int> ans;

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push(make_pair(-dist[start], start));

    while (!pq.empty()) {
        int currVal = -pq.top().first;
        int currPos = pq.top().second;
        pq.pop();

        if (dist[currPos] < currVal) continue;

        for (int i = 0; i < line[currPos].size(); i++) {
            int nextPos = line[currPos][i].first;
            int nextVal = currVal + line[currPos][i].second;

            if (dist[nextPos] > nextVal) {
                path[line[currPos][i].first] = currPos;
                dist[nextPos] = nextVal;
                pq.push(make_pair(-nextVal, nextPos));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int k = 1; k <= t; k++) {
        ans.clear();
        fill(dist, dist + 30, INF);
        for (int i = 0; i < 30; i++) {
            line[i].clear();
            path[i] = i;
        }

        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            line[a].push_back(make_pair(b, c));
            line[b].push_back(make_pair(a, c));
        }

        dijkstra(0);

        if (dist[m - 1] >= INF) {
            cout << "Case #" << k << ": " << -1 << '\n';
        }
        else {
            cout << "Case #" << k << ": ";
            int x = m - 1;
            while (x != path[x]) {
                ans.push_back(x);
                x = path[x];
            }
            ans.push_back(x);
            reverse(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << ans[i] << " ";
            }
            cout << '\n';
        }
    }
}