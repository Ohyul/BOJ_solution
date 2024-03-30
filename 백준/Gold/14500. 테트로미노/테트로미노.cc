#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<vector<int>> board;
vector<vector<bool>> visited;
int ans = 0;
int max_val = 0;
vector<pair<int, int>> d = { {-1, 0}, {0, -1}, {1, 0}, {0, 1} };

void dfs(int col, int row, int step, int total) {
    if (total + max_val * (4 - step) <= ans) {
        return;
    }

    if (step == 4) {
        ans = max(ans, total);
        return;
    }

    for (auto& direction : d) {
        int currC = col + direction.first;
        int currR = row + direction.second;

        if (currC >= 0 && currC < N && currR >= 0 && currR < M && !visited[currC][currR]) {
            if (step == 2) {
                visited[currC][currR] = true;
                dfs(col, row, step + 1, total + board[currC][currR]);
                visited[currC][currR] = false;
            }

            visited[currC][currR] = true;
            dfs(currC, currR, step + 1, total + board[currC][currR]);
            visited[currC][currR] = false;
        }
    }
}

int main() {
    cin >> N >> M;
    board.resize(N, vector<int>(M));
    visited.resize(N, vector<bool>(M, false));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> board[i][j];
            max_val = max(max_val, board[i][j]);
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            visited[i][j] = true;
            dfs(i, j, 1, board[i][j]);
            visited[i][j] = false;
        }
    }

    cout << ans;
}
