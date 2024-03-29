#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Coin {
    int val, num;
};

bool compare(const Coin& l, const Coin& r) {
    return l.val < r.val;
}

int n;
vector <Coin> arr;
int totalSum;
vector <int> dp;
int each;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (each++ < 3) {
        cin >> n;
        totalSum = 0;
        arr.clear();
        arr.resize(n);
        dp.clear();
        dp.resize(100010);

        for (int i = 0; i < n; i++) {
            cin >> arr[i].val >> arr[i].num;
            totalSum += arr[i].val * arr[i].num;
        }

        sort(arr.begin(), arr.end(), compare);

        if (totalSum % 2 == 1) {
            cout << "0\n";
            continue;
        }


        dp[0] = 1;
        for (auto& el : arr) {
            for (int i = 50000; i >= el.val; i--) {
                if (dp[i - el.val] != 0) {
                    for (int j = 0; (j < el.num) && (i + j * el.val <= 50000); j++) {
                        dp[i + j * el.val] = 1;
                    }
                }
            }
        }
        cout << dp[totalSum / 2] << '\n';
    }
}
