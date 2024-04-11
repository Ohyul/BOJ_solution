#include <iostream>
#include <string>
#include <climits>
using namespace std;

int N, opIdx;
int ans = INT_MIN;
int Num[22], Oper[22];
string inst;

int calc(int num1, int num2, char B) {
    if (B == '+') return num1 + num2;
    else if (B == '-') return num1 - num2;
    else if (B == '*') return num1 * num2;
}

void dfs(int Idx, int val) {
    if (Idx >= opIdx) {
        ans = max(ans, val);
        return;
    }
    int currVal = calc(val, Num[Idx + 1], Oper[Idx]);
    dfs(Idx + 1, currVal);
    if (Idx + 1 < opIdx) {
        int nextVal = calc(Num[Idx + 1], Num[Idx + 2], Oper[Idx + 1]);
        int currVal = calc(val, nextVal, Oper[Idx]);
        dfs(Idx + 2, currVal);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int Idx = 0;
    int Idx2 = 0;
    cin >> inst;
    for (int i = 0; i < inst.length(); i++) {
        if (i % 2 == 0) Num[Idx++] = inst[i] - '0';
        else Oper[Idx2++] = inst[i];
    }
    opIdx = N / 2;
    dfs(0, Num[0]);

    cout << ans;
}