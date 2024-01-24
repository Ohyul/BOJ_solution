#include <iostream>

using namespace std;

int arr[1025][1025];
int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val;
            cin >> val;
            if (i == 1 && j == 1)
                arr[i][j] = val;
            else if (i == 1 && j != 1)
                arr[i][j] = val + arr[i][j - 1];
            else if (i != 1 && j == 1)
                arr[i][j] = val + arr[i - 1][j];
            else
                arr[i][j] = val + arr[i][j - 1] + arr[i - 1][j] - arr[i - 1][j - 1];
        }
    }

    for (int i = 0; i < m; i++) {
        int str_r, str_c, end_r, end_c, sum = 0;
        cin >> str_r >> str_c >> end_r >> end_c;

        sum = arr[end_r][end_c] - arr[str_r - 1][end_c] - arr[end_r][str_c - 1] + arr[str_r - 1][str_c - 1];

        cout << sum << "\n";
    }
}
