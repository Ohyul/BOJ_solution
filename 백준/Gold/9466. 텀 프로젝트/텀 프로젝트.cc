#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ans;
int arr[100100], visited[100100], cycle[100100];
int tc;

void dfs(int now, int start) {
    if (visited[now] == 2) return; 
    if (visited[now] == 1) { 
        ans++;
        for (int i = arr[now]; i != now; i = arr[i]) {
            ans++;
        }
        return;
    }
    visited[now] = 1; 
    dfs(arr[now], start); 
    visited[now] = 2; 
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    while (tc-- > 0) {
        cin >> n;
        
        ans = 0;
        for (int i = 1; i <= n; i++) {
            visited[i] = 0;
            cycle[i] = 0;
            cin >> arr[i];
        }

        for (int i = 1; i <= n; i++) {
            if (visited[i] == 0) {
                dfs(i, i);
            }
        }

        cout << n - ans << endl;
    }
}
