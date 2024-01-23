#include <iostream>
using namespace std;
const int MAX_LEN = 1000;
int dp[MAX_LEN + 1][MAX_LEN + 1];

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int len_1 = str1.length();
    int len_2 = str2.length();

    for (int i = 0; i <= len_1; i++) {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= len_2; i++) {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= len_1; i++) {
        for (int j = 1; j <= len_2; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[len_1][len_2];

    return 0;
}