#include <iostream>
#include <vector>
using namespace std;

int A, B;
int ans;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> A >> B;

    vector<int> lst(100010, 1);
    lst[0] = lst[1] = 0;

    for (int i = 2; i < 100010; ++i) {
        int n = 2;
        while (i * n < 100010) {
            lst[i * n] = 0;
            n++;
        }
    }

    vector<int> prime_lst;
    for (int idx = 0; idx < 100010; ++idx) {
        if (lst[idx] == 1) {
            prime_lst.push_back(idx);
        }
    }

    for (int num = A; num <= B; ++num) {
        int temp = num;
        vector<int> temp_lst;
        int cnt = 0, n = 0;

        if (lst[temp] == 1) {
            continue;
        }

        while (temp > 1) {
            if (lst[temp]) {
                cnt += lst[temp];
                temp = 1;
            }
            else {
                if (temp % prime_lst[n]) {
                    n++;
                }
                else {
                    temp_lst.push_back(temp);
                    temp /= prime_lst[n];
                    cnt++;
                }
            }
        }

        for (int idx = 0; idx < temp_lst.size(); ++idx) {
            lst[temp_lst[idx]] = cnt - idx;
        }

        if (lst[cnt] == 1) {
            ans++;
        }
    }

    cout << ans;
}
