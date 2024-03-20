#include <iostream>
#include <cstring> // for memset
using namespace std;

int n;
int arr[510][510], dp[510][510];
int maxi = 0;
int dr[4] = { 1, -1, 0 ,0 };
int dc[4] = { 0, 0, 1, -1 };

int dfs(int row, int col) {
    if (dp[row][col] != -1) return dp[row][col];
    int longest = 1;
    for (int i = 0; i < 4; i++) {
        int nextR = row + dr[i];
        int nextC = col + dc[i];
        if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n && arr[nextR][nextC] > arr[row][col]) {
            longest = max(longest, 1 + dfs(nextR, nextC));
        }
    }
    return dp[row][col] = longest;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    memset(dp, -1, sizeof(dp)); 

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            maxi = max(maxi, dfs(i, j));
        }
    }

    cout << maxi;
}
