#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Meeting {
    int start, end, person;

    Meeting(int s, int e, int p) : start(s), end(e), person(p) {}

    bool operator<(const Meeting& right) const {
        return end < right.end;
    }
};

int N;
vector<Meeting> MeetingList;
vector<int> startEnd;
unordered_map<int, int> um;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (int i = 0; i < N; i++) {
        int start, end, person;
        cin >> start >> end >> person;
        MeetingList.push_back({ start, end, person });
        startEnd.push_back(start);
        startEnd.push_back(end);
    }

    sort(startEnd.begin(), startEnd.end());
    int idx = 0;
    for (int i : startEnd) {
        if (!um.count(i)) {
            um[i] = idx++;
        }
    }

    vector<int> dp(idx, 0);

    sort(MeetingList.begin(), MeetingList.end());

    int MeetingIdx = 0;
    for (int i = 1; i < idx; i++) {
        int end = MeetingList[MeetingIdx].end;
        if (i == um[end]) {
            int current = dp[um[MeetingList[MeetingIdx].start]] + MeetingList[MeetingIdx].person;
            if (dp[i - 1] < current)
                dp[i] = current;
            else
                dp[i] = dp[i - 1];
            MeetingIdx++;
        }
        else {
            dp[i] = dp[i - 1];
        }
    }

    cout << dp[idx - 1] << endl;
}
