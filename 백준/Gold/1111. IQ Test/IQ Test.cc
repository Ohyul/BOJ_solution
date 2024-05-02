#include <iostream>
#include <vector>
using namespace std;

int N, a, b, diff1, diff2;
vector<int> v;
int flag;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    v.resize(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    if (N == 1) {
        cout << "A";
        return 0;
    }
    else if (N == 2) {
        if (v[0] == v[1])
            cout << v[0];
        else
            cout << "A";
        return 0;
    }

    diff1 = v[1] - v[0];
    diff2 = v[2] - v[1];

    a = (diff1 != 0) ? diff2 / diff1 : 0;
    b = v[1] - a * v[0];

    flag = 1;
    for (int i = 1; i < N; i++) {
        if (v[i] != (v[i - 1] * a + b)) {
            flag = 0;
            break;
        }
    }

    if (flag)
        cout << v[N - 1] * a + b;
    else
        cout << "B";
}
