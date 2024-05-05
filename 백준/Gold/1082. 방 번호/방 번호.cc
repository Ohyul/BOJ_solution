#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct Item {
    int val;
    int idx;
};

int N, M, P[10];
vector<Item> p;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        p.push_back({ P[i], i });
    }
    cin >> M;
    sort(p.begin(), p.end(), [](const Item& a, const Item& b) {
        return a.val < b.val;
        });

    string ret;
    if (N == 1) {
        cout << "0" << endl;
        return 0;
    }

    if (p[0].idx != 0) {
        int cnt = M / p[0].val;
        for (int i = 0; i < cnt; i++)
            ret += to_string(p[0].idx);
        M -= cnt * p[0].val;
    }
    else {
        int m = M - p[1].val;
        if (m < 0) {
            cout << "0" << endl;
            return 0;
        }
        ret += to_string(p[1].idx);
        int cnt = m / p[0].val;
        for (int i = 0; i < cnt; i++)
            ret += to_string(p[0].idx);
        M = m - cnt * p[0].val;
    }

    for (int i = 0; i < ret.size(); i++) {
        int flag = 0;
        int cur = P[ret[i] - '0'];
        for (int j = N - 1; j >= 0; j--) {
            if (M - (P[j] - cur) >= 0) {
                M -= P[j] - cur;
                flag = 1;
                ret[i] = j + '0';
            }
            if (flag) break;
        }
        if (!flag) break;
    }

    cout << ret;
}
