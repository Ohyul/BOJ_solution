#include <iostream>
using namespace std;

int N, K, ans;

int buy(int x) {
    int cnt = 0;
    while (x > 0) {
        if (x % 2 == 1) cnt++;
        x = x / 2;
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;

    if (N <= K) {
        cout << 0;
    }

    else {
        while (true) {
            int temp = buy(N);
            if (temp <= K) break;
            ans++;
            N++;
        }
        cout << ans;
    }
}
