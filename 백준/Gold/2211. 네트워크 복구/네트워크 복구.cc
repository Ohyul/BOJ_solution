#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<pair<int, int>> graph[1010];
int d[1010];
int route[1010];
int n, m;
int a, b, c;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({ 0, start });
    d[start] = 0;

    while (!pq.empty()) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (d[curr] < dist) continue;
        for (int i = 0; i < graph[curr].size(); i++) {
            int nextVal = graph[curr][i].second;
            int next = graph[curr][i].first;

            if (dist + nextVal < d[next]) {
                route[next] = curr;
                d[next] = dist + nextVal;
                pq.push({ d[next], next });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }

    fill(d, d + n + 1, INT_MAX);
    dijkstra(1);

    cout << n - 1 << '\n';
    for (int i = 2; i <= n; i++) cout << route[i] << " " << i << '\n';
}