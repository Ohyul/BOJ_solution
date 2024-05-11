#include <iostream>
#include <vector>
#include <queue>
#define endl "\n"
using namespace std;

const int dx[] = { 0, 0, 1, -1 };
const int dy[] = { 1, -1, 0, 0 };

void Input(vector<vector<int>>& arr) {
    for (int i = 0; i < 5; i++) {
        string Inp;
        cin >> Inp;
        for (int j = 0; j < Inp.length(); j++) {
            if (Inp[j] == 'Y') arr[i][j] = 1;
            else if (Inp[j] == 'S') arr[i][j] = 2;
        }
    }
}

bool MoreThanFour(const vector<vector<int>>& arr, const vector<bool>& Select) {
    int Cnt = 0;
    for (int i = 0; i < 25; i++) {
        if (Select[i]) {
            int x = i / 5;
            int y = i % 5;
            if (arr[x][y] == 2) Cnt++;
        }
    }
    return Cnt >= 4;
}

bool Adjacency(const vector<vector<int>>& arr, const vector<bool>& Select) {
    queue<pair<int, int>> Q;
    bool Queue_Select[5][5] = { false };
    bool Check_ans = false;
    int Tmp = 0;
    for (int i = 0; i < 25; i++) {
        if (Select[i]) {
            int x = i / 5;
            int y = i % 5;
            if (Tmp == 0) {
                Q.push({ x, y });
                Queue_Select[x][y] = true;
                Tmp++;
            }
        }
    }
    int Cnt = 1;
    while (!Q.empty()) {
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        if (Cnt == 7) {
            Check_ans = true;
            break;
        }
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
                if (Select[nx * 5 + ny] && !Queue_Select[nx][ny]) {
                    Queue_Select[nx][ny] = true;
                    Q.push({ nx, ny });
                    Cnt++;
                }
            }
        }
    }
    return Check_ans;
}

void DFS(int Idx, int Cnt, vector<bool>& Select, const vector<vector<int>>& arr, int& ans) {
    if (Cnt == 7) {
        if (MoreThanFour(arr, Select) && Adjacency(arr, Select)) {
            ans++;
        }
        return;
    }
    for (int i = Idx; i < 25; i++) {
        if (!Select[i]) {
            Select[i] = true;
            DFS(i, Cnt + 1, Select, arr, ans);
            Select[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> arr(5, vector<int>(5));
    vector<bool> Select(25);
    int ans = 0;

    Input(arr);
    DFS(0, 0, Select, arr, ans);
    cout << ans << endl;
}