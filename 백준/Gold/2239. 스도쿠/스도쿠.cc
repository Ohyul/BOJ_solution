#include <iostream>
using namespace std;

int arr[9][9];
int complete = 0;

void dfs(int row, int col, int val) {
    if (complete == 1) return;

    arr[row][col] = val;

    int rowCheck[10] = { 0 }, colCheck[10] = { 0 }, blockCheck[10] = { 0 };

    int rowStr = (row / 3) * 3;
    int colStr = (col / 3) * 3;

    for (int i = rowStr; i < rowStr + 3; i++) {
        for (int j = colStr; j < colStr + 3; j++) {
            blockCheck[arr[i][j]]++;
        }
    }
    for (int i = 0; i < 9; i++) {
        rowCheck[arr[i][col]]++;
        colCheck[arr[row][i]]++;
    }

    for (int i = 1; i <= 9; i++) {
        if (rowCheck[i] >= 2 || colCheck[i] >= 2 || blockCheck[i] >= 2) {
            arr[row][col] = 0;
            return;
        }
    }

    int nextR = -1, nextC = -1;
    for (int i = 0; i < 9; i++) {
        if (nextR != -1) break;
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                nextR = i, nextC = j;
                break;
            }
        }
    }

    if (nextR == -1 && nextC == -1) {
        complete = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << arr[i][j];
            }
            cout << "\n";
        }
        return;
    }

    for (int i = 1; i <= 9; i++) {
        dfs(nextR, nextC, i);
    }

    arr[row][col] = 0;
}

int main() {
    for (int i = 0; i < 9; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < 9; j++) {
            arr[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (arr[i][j] == 0) {
                dfs(i, j, 1); 
            }
        }
    }
}