#include <iostream>
#include <string>
using namespace std;

string tar, in;
int n, len, cnt;

bool is_substring_circular(const string& s, const string& sub) {
    int s_len = s.length();
    int sub_len = sub.length();

    for (int i = 0; i < s_len; i++) {
        int j = 0;
        while (j < sub_len && s[(i + j) % s_len] == sub[j]) {
            j++;
        }
        if (j == sub_len) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> tar >> n;
    len = tar.length();

    for (int i = 0; i < n; i++) {
        cin >> in;
        if (is_substring_circular(in, tar)) cnt++;
    }
    cout << cnt;
}
