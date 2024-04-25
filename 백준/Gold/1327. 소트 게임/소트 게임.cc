#include <iostream>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

int N, K, len;
string tar, origin;
queue<pair<string, int>> que;
set<string> visited;
int ans = -1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        char num;
        cin >> num;
        tar += num;
    }

    origin = tar;
    sort(tar.begin(), tar.end());

    que.push({ origin, 0 });

    len = N - K; 
    while (ans == -1 && !que.empty()) {
        string curr = que.front().first;
        int depth = que.front().second;
        que.pop();

        if (curr == tar) {
            ans = depth;
            break;
        }

        if (!visited.count(curr)) {
            for (int i = 0; i <= len; i++) {
                string num1 = curr.substr(0, i);
                string num2 = curr.substr(i, K);
                reverse(num2.begin(), num2.end());
                string num3 = curr.substr(K + i, N);
                que.push({ num1 + num2 + num3, depth + 1 });
            }
            visited.insert(curr);
        }
    }

    cout << ans << "\n";
}
