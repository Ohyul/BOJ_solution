#include <iostream>
#include <climits>
using namespace std;

int arr[5050], n, m;
int maxi, mini;
int str, dst, ans;

int isValid(int mid) {
    int low = arr[0];
    int high = arr[0];
    int d = 1;

    for (int i = 0; i < n; i++) {
        if (high < arr[i]) {
            high = arr[i];
        }
        if (low > arr[i]) {
            low = arr[i];
        }

        if (high - low > mid) {
            d++;
            low = arr[i]; 
            high = arr[i];
        }
    }
    return m >= d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        maxi = max(maxi, arr[i]);
    }

    dst = maxi;
    ans = INT_MAX; 

    while (str <= dst) {
        int mid = (str + dst) / 2;

        if (isValid(mid)) {
            dst = mid - 1;
            ans = min(ans, mid);
        }
        else {
            str = mid + 1;
        }
    }
    cout << ans;
}
