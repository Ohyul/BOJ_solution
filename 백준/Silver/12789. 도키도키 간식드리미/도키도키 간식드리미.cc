#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
int num, curr, Next = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> num;

    while (num--) {
        cin >> curr;

        if (curr == Next) {
            Next++;
        }
        else {
            s.push(curr);
        }

        while (!s.empty() && s.top() == Next) {
            s.pop();
            Next++;
        }
    }

    if (s.empty()) {
        cout << "Nice";
    }
    else {
        cout << "Sad";
    }
}
