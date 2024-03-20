#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[30010];
int dp[3010];
int candy[30010], child[30010];
int n, m, k;


int find(int x) {
    if (x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

void getUnion(int x, int y) {
    x = find(x);
    y = find(y);

    if (x < y)
        parent[y] = x;
    else
        parent[x] = y;
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 1; i <= n; i++) {
        cin >> candy[i];
        child[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        getUnion(a, b);
    }

    for (int i = 1; i <= n; i++)
        if (parent[i] != i) {
            int p = find(i);
            candy[p] += candy[i];
            child[p] += child[i];
        }

    for (int i = 1; i <= n; i++) {
        if (parent[i] != i)
            continue;
        for (int j = k - 1; j - child[i] >= 0; j--)
            dp[j] = max(dp[j], dp[j - child[i]] + candy[i]);
    }

    cout << dp[k - 1];
}
