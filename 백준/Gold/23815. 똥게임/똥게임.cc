#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int Calc(int x, string s) {
    char oper = s[0];
    int num = s[1] - '0';
    if (x == 0) {
        return 0;
    }
    int ans;
    if (oper == '+')
        ans = x + num;
    else if (oper == '-')
        ans = x - num;
    else if (oper == '*')
        ans = x * num;
    else if (oper == '/')
        ans = x / num;
    return max(0, ans);
}

int N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    vector<vector<string>> choice(N + 1, vector<string>(2));
    vector<vector<int>> dp(N + 1, vector<int>(2));

    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> choice[i][j];
        }
    }

    dp[0][0] = dp[0][1] = 1;

    for (int i = 1; i <= N; ++i) {
        int a = Calc(dp[i - 1][0], choice[i][0]);
        int b = Calc(dp[i - 1][0], choice[i][1]);
        int c = Calc(dp[i - 1][1], choice[i][0]);
        int d = Calc(dp[i - 1][1], choice[i][1]);
        dp[i][0] = max(a, b);
        dp[i][1] = max({ dp[i - 1][0], c, d });

        if (max(dp[i][0], dp[i][1]) <= 0) {
            cout << "ddong game";
            return 0;
        }
    }

    cout << max(dp[N][0], dp[N][1]);
}
