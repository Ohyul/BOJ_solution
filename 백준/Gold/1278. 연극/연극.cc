#include <iostream>
#include <vector>
using namespace std;

int N, visit[1 << 20], v;
vector<int> curr, ans;

void sol(int n, int m) {
    if (n != 0 && m == 0 && n > v) {
        v = n;
        ans = curr;
        return;
    }

    for (int i = 0; i < N; i++) {
        if (((1 << i) & m) > 0) {
            int k = (~(1 << i)) & m;
            if ((n != 0 && k == 0) || !visit[k]) {
                visit[k] = 1;
                curr.push_back(i);
                sol(n + 1, k);
                curr.pop_back();
            }
        }

        if (((1 << i) & m) == 0) {
            int k = (1 << i) | m;
            if (!visit[k]) {
                visit[k] = 1;
                curr.push_back(i);
                sol(n + 1, k);
                curr.pop_back();
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    sol(0, 0);
    cout << v - 1 << '\n';
    for (auto a : ans) {
        cout << a + 1 << "\n";
    }
}
