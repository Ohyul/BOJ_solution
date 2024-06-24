#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int n;
ll ans;

ll calc(const vector<vector<ll>>& arr) {
    ll res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = max(res, arr[i][j]);
        }
    }
    return res;
}

vector<vector<ll>> move(vector<vector<ll>> arr, int dr, int dc) {
    vector<vector<bool>> check(n, vector<bool>(n, false));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int r = (dr == 1) ? n - 1 - i : i;
            int c = (dc == 1) ? n - 1 - j : j;
            if (arr[r][c] == 0)
                continue;
            int nr = r + dr, nc = c + dc;
            while (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (arr[nr][nc] == arr[r][c] && !check[nr][nc]) {
                    arr[nr][nc] *= 2;
                    arr[r][c] = 0;
                    check[nr][nc] = true;
                    break;
                }
                else if (arr[nr][nc] == 0) {
                    arr[nr][nc] = arr[r][c];
                    arr[r][c] = 0;
                }
                else {
                    break;
                }
                r = nr;
                c = nc;
                nr += dr;
                nc += dc;
            }
        }
    }
    return arr;
}

void dfs(int L, vector<vector<ll>>& arr, ll currentMax) {
    ans = max(ans, currentMax);
    if (L == 5) return;
    vector<vector<ll>> newArr;
    ll newMax;
    newArr = move(arr, 0, 1);
    newMax = calc(newArr);
    if (newArr != arr) {
        dfs(L + 1, newArr, newMax);
    }
    newArr = move(arr, 0, -1);
    newMax = calc(newArr);
    if (newArr != arr) {
        dfs(L + 1, newArr, newMax);
    }
    newArr = move(arr, 1, 0);
    newMax = calc(newArr);
    if (newArr != arr) {
        dfs(L + 1, newArr, newMax);
    }
    newArr = move(arr, -1, 0);
    newMax = calc(newArr);
    if (newArr != arr) {
        dfs(L + 1, newArr, newMax);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    vector<vector<ll>> arr(n, vector<ll>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    ll maxi = calc(arr);
    dfs(0, arr, maxi);
    cout << ans;
}
