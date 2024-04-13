#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int dp[510][510];
vector<int> r, c;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    r.resize(N);
    c.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> r[i] >> c[i];
    }


    for (int i = 0; i < N - 1; i++) {
        dp[i][i + 1] = r[i] * r[i + 1] * c[i + 1];
    }

    for (int dist = 2; dist < N; dist++) {
        for (int prev = 0; prev < N - dist; prev++) {
            int next = prev + dist;
            for (int i = prev; i < next; i++) {
                int res = dp[prev][i] + dp[i + 1][next] + r[prev] * c[i] * c[next];
                if (dp[prev][next] == 0 || dp[prev][next] > res)
                    dp[prev][next] = res;
            }
        }
    }
    cout << dp[0][N - 1];
}
