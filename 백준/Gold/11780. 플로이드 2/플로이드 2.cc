#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int N, M;
int Cost[110][110];
int Route[110][110];
vector<int> V;

void Find_Route(int Start, int End) {
    if (Route[Start][End] == 0) {
        V.push_back(Start);
        V.push_back(End);
        return;
    }
    Find_Route(Start, Route[Start][End]);
    V.pop_back();
    Find_Route(Route[Start][End], End);
}


int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            Cost[i][j] = 1e9;
        }
    }
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Cost[a][b] = min(Cost[a][b], c);
    }

    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (i == j) continue;
                if (Cost[i][j] > Cost[i][k] + Cost[k][j]) {
                    Cost[i][j] = Cost[i][k] + Cost[k][j];
                    Route[i][j] = k;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (Cost[i][j] == 1e9) cout << "0 ";
            else cout << Cost[i][j] << " ";
        }
        cout << "\n";
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (Cost[i][j] == 1e9) cout << "0 ";
            else {
                V.clear();
                Find_Route(i, j);
                cout << V.size() << " ";
                for (auto el : V) { 
                    cout << el << " "; 
                }
            }
            cout << "\n";
        }
    }
}
