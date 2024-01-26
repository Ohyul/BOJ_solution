#include <iostream>

using namespace std;

int arr[1010];
int dp[1010];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        dp[i] = 1;  
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (arr[i] > arr[j] && dp[i] <= dp[j]) {
                dp[i] = dp[j] + 1;
            }
        }
    }
    int maxi = -1;
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, dp[i]);
    }
    cout << maxi;
    return 0;  
}
