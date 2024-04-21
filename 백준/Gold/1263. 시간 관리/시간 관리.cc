#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;

int N;
vector<pair<int, int>> task;
int ans = -1;

bool isPoss(int str) {
    int time = str;
    for (auto el: task) {
        if (time + el.second > el.first) {
            return false;
        }
        time += el.second;
    }
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    task.resize(N);

    for (int i = 0; i < N; i++) {
        cin >> task[i].second >> task[i].first; 
    }

    sort(task.begin(), task.end());

    ll l = 0, r = 1000 * 1000000;
    while (l <= r) {
        ll mid = (l + r) / 2;
        if (isPoss(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }

    cout << ans;
}
