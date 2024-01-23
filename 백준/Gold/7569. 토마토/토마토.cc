#include <iostream>
#include <queue>
using namespace std;

const int MAX_SIZE = 100;

int arr[MAX_SIZE][MAX_SIZE][MAX_SIZE];
int row, col, height;

int dr[] = { 1, -1, 0, 0, 0, 0 };
int dc[] = { 0, 0, 1, -1, 0, 0 };
int dh[] = { 0, 0, 0, 0, 1, -1 };

struct Cell {
    int x, y, z;
};

bool isValid(int x, int y, int z) {
    return (x >= 0 && x < row && y >= 0 && y < col && z >= 0 && z < height);
}

int bfs() {
    queue<Cell> q;
    int days = -1;

    for (int k = 0; k < height; k++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j][k] == 1) {
                    q.push({ i, j, k });
                }
            }
        }
    }

    while (!q.empty()) {
        int size = q.size();
        days++;

        for (int i = 0; i < size; i++) {
            Cell current = q.front();
            q.pop();
            for (int d = 0; d < 6; d++) {
                int nx = current.x + dr[d];
                int ny = current.y + dc[d];
                int nz = current.z + dh[d];

                if (isValid(nx, ny, nz) && arr[nx][ny][nz] == 0) {
                    arr[nx][ny][nz] = 1;
                    q.push({ nx, ny, nz });
                }
            }
        }
    }

    return days;
}

int main() {
    cin >> col >> row >> height;

    for (int k = 0; k < height; k++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                cin >> arr[i][j][k];
            }
        }
    }

    int days = bfs();

    for (int k = 0; k < height; k++) {
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (arr[i][j][k] == 0) {
                    cout << "-1";
                    return 0;
                }
            }
        }
    }

    cout << days;

    return 0;
}
