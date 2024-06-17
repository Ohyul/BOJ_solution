#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;

        int m = max(R, C);
        int n = min(R, C);
        int k = m - n;

        long long n1 = static_cast<long long>(n);
        long long white = (n1 * (n1 + 1) * (2 * n1 + 1)) / 3 - n1 * (n1 + 1) + n1 * (n1 + 1) * k - n1 * k + n1;
        long long black = (n1 * (n1 + 1) * (2 * n1 + 1)) / 3 - n1 * (n1 + 1) + n1 * (n1 + 1) * k - n1 * k;

        cout << white << " " << black << "\n";
    }
}
