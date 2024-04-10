#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int T;


void solve() {
    cin >> N >> K;
    vector<int> D(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> D[i];
    }
    vector<vector<int>> graph(N + 1);
    vector<int> ind(N + 1, 0);

    for (int i = 0; i < K; ++i) {
        int X, Y;
        cin >> X >> Y;
        graph[X].push_back(Y);
        ind[Y]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; ++i) {
        if (ind[i] == 0) {
            q.push(i);
        }
    }

    vector<int> build(N + 1, 0);
    while (!q.empty()) {
        int here = q.front();
        q.pop();
        build[here] += D[here];
        for (int there : graph[here]) {
            build[there] = max(build[there], build[here]);
            ind[there]--;
            if (ind[there] == 0) {
                q.push(there);
            }
        }
    }
    int target;
    cin >> target;
    cout << build[target] << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
