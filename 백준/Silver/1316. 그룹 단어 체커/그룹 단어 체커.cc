#include <iostream>
#include <string>
using namespace std;

int n, cnt = 0;
string str;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> str;
        int alphabet[26] = { 0 };
        int vor = -1, flag = 0;

        for (int j = 0; j < str.length(); j++) {
            int current = str[j] - 'a';
            if (vor != current && alphabet[current] > 0) {
                flag = 1;
                break;

            }
            alphabet[current]++;
            vor = current;
        }
        if (flag == 0) cnt++;
    }
    cout << cnt;
}
