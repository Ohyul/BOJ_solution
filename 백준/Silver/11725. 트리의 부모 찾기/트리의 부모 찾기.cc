#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> tree(n + 1);
    vector<int> parent(n + 1, 0);

    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : tree[node]) {
            if (parent[neighbor] == 0) {
                parent[neighbor] = node;
                q.push(neighbor);
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << parent[i] << "\n";
    }

    return 0;
}
