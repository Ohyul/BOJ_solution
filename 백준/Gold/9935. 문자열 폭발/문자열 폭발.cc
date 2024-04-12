#include <iostream>
#include <string>
#include <deque>
using namespace std;

bool check(const string& bomb, deque<char>& dq) {
    if (dq.size() < bomb.size()) {
        return false;
    }
    string dq_str(dq.begin(), dq.end());
    return dq_str == bomb;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string s, bomb;
    cin >> s >> bomb;

    deque<char> result;

    for (char c : s) {
        result.push_back(c);
        if (result.size() >= bomb.size()) {
            deque<char> temp(result.end() - bomb.size(), result.end());
            if (check(bomb, temp)) {
                for (int i = 0; i < bomb.size(); ++i) {
                    result.pop_back();
                }
            }
        }
    }

    if (result.empty()) {
        cout << "FRULA";
    }
    else {
        for (char c : result) {
            cout << c;
        }
    }

    return 0;
}
