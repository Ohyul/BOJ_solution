#include <iostream>
#include <vector>
#include <string>
using namespace std;

int N, K;
bool alphabets[26];
int ans;
vector<string> v;

void dfs(int idx, int left) {
    if (!left) {
        int cnt = 0;
        for (string el : v) {
            bool flag = true;
            for (char ch : el) {
                if (!alphabets[ch - 'a']) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        ans = max(ans, cnt);
        if (ans == N) {
            cout << N << '\n';
            exit(0);
        }
        return;
    }
    for (int i = idx; i < 26; i++) {
        if (alphabets[i]) continue;
        alphabets[i] = true;
        dfs(i, left - 1);
        alphabets[i] = false;
    }
}

int main() {
    ios::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);

    cin >> N >> K;
    string str = "";
    for (int i = 0; i < N; i++) {
        cin >> str;
        v.push_back(str.substr(4, str.length() - 8));
    }
    if (K < 5) {
        cout << 0 << '\n';
        return 0;
    }

    alphabets[0] = true; 
    alphabets[2] = true; 
    alphabets[8] = true;
    alphabets[13] = true; 
    alphabets[19] = true;

    dfs(0, K - 5);
    cout << ans;
}