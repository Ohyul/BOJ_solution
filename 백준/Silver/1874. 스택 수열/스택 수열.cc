#include <iostream>
#include <stack>
using namespace std;

stack<int> s;
string op;
int n, i = 1;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    while (n--) {
        int num;
        cin >> num;

        if (i <= num) {
            while (i <= num) {
                s.push(i);
                op += '+';
                i++;
            }
            s.pop();
            op += '-';
        }
        else {
            if (s.top() < num) {
                cout << "NO\n";
                return 0;
            }
            else {
                s.pop();
                op += '-';
            }
        }
    }

    for (int j = 0; j < op.length(); j++) {
        cout << op[j] << "\n";
    }
}