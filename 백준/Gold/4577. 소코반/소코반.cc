#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int r, c;
vector<string> arr;
pair<int, int> Curr;
int dcdr[4][2] = { {0,-1},{-1,0},{0,1},{1,0} };
int game;
string ans;

bool Finish() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (arr[i][j] == 'b')
                return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (true) {
        game++;
        arr.clear();

        cin >> r >> c;
        if (r == 0 && c == 0) {
            break;
        }
        for (int i = 0; i < r; i++) {
            string input;
            cin >> input;

            arr.push_back(input);

            for (int j = 0; j < c; j++) {
                if (arr[i][j] == 'w' || arr[i][j] == 'W') {
                    Curr = make_pair(i, j);
                }
            }
        }

        string inst;
        cin >> inst;

        for (int i = 0; i < inst.size(); i++) {
            pair<int, int> Next;
            pair<int, int> Next2;

            if (Finish() == true) {
                ans = "complete";
                break;
            }

            if (inst[i] == 'L') {
                Next = make_pair(Curr.first + dcdr[0][0], Curr.second + dcdr[0][1]);
                Next2 = make_pair(Next.first + dcdr[0][0], Next.second + dcdr[0][1]);
            }

            else if (inst[i] == 'U') {
                Next = make_pair(Curr.first + dcdr[1][0], Curr.second + dcdr[1][1]);
                Next2 = make_pair(Next.first + dcdr[1][0], Next.second + dcdr[1][1]);
            }

            else if (inst[i] == 'R') {
                Next = make_pair(Curr.first + dcdr[2][0], Curr.second + dcdr[2][1]);
                Next2 = make_pair(Next.first + dcdr[2][0], Next.second + dcdr[2][1]);
            }

            else if (inst[i] == 'D') {
                Next = make_pair(Curr.first + dcdr[3][0], Curr.second + dcdr[3][1]);
                Next2 = make_pair(Next.first + dcdr[3][0], Next.second + dcdr[3][1]);
            }

            if (arr[Next.first][Next.second] == '.' || arr[Next.first][Next.second] == '+') {
                if (arr[Curr.first][Curr.second] == 'w')
                    arr[Curr.first][Curr.second] = '.';
                else if (arr[Curr.first][Curr.second] == 'W')
                    arr[Curr.first][Curr.second] = '+';

                if (arr[Next.first][Next.second] == '.')
                    arr[Next.first][Next.second] = 'w';
                else if (arr[Next.first][Next.second] == '+')
                    arr[Next.first][Next.second] = 'W';

                Curr = Next;
            }

            if (arr[Next.first][Next.second] == 'b' || arr[Next.first][Next.second] == 'B') {
                if (arr[Next2.first][Next2.second] == '.' || arr[Next2.first][Next2.second] == '+') {
                    if (arr[Next2.first][Next2.second] == '.')
                        arr[Next2.first][Next2.second] = 'b';
                    else if (arr[Next2.first][Next2.second] == '+')
                        arr[Next2.first][Next2.second] = 'B';

                    if (arr[Next.first][Next.second] == 'b')
                        arr[Next.first][Next.second] = '.';
                    else if (arr[Next.first][Next.second] == 'B')
                        arr[Next.first][Next.second] = '+';

                    if (arr[Curr.first][Curr.second] == 'w')
                        arr[Curr.first][Curr.second] = '.';
                    else if (arr[Curr.first][Curr.second] == 'W')
                        arr[Curr.first][Curr.second] = '+';

                    if (arr[Next.first][Next.second] == '.')
                        arr[Next.first][Next.second] = 'w';
                    else if (arr[Next.first][Next.second] == '+')
                        arr[Next.first][Next.second] = 'W';

                    Curr = Next;
                }
            }

            if (i == inst.size() - 1) {
                if (Finish() == true) {
                    ans = "complete";
                    break;
                }

                else {
                    ans = "incomplete";
                    break;
                }
            }
        }

        cout << "Game " << game << ": " << ans << "\n";
        for (int i = 0; i < r; i++) {
            cout << arr[i] << "\n";
        }
    }
}