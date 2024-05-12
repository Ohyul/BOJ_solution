#include <iostream>
#include <vector>
using namespace std;

int n, c, r, d, g;
int arr[110][110];
int dr[4] = { 0, -1, 0, 1 };
int dc[4] = { 1, 0, -1, 0 };
int cnt;

vector<int> v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    while (n--) {
        cin >> c >> r >> d >> g;
        v.clear();

        arr[r][c] = 1;
        r += dr[d];
        c += dc[d];
        arr[r][c] = 1;

        v.push_back(d);

        while (g--) {
            int size = v.size();
            for (int i = size - 1; i >= 0; i--) {
                int nd = (v[i] + 1) % 4;
                r += dr[nd];
                c += dc[nd];
                arr[r][c] = 1;
                v.push_back(nd);
            }
        }
    }
    for (int i = 0; i < 110; i++) {
        for (int j = 0; j < 110; j++) {
            if (arr[i][j] == 1 && arr[i][j + 1] == 1 && arr[i + 1][j] == 1 && arr[i + 1][j + 1] == 1)
                cnt++;
        }
    }    

    cout << cnt;
}
