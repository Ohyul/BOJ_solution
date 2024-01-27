#include <iostream>
#include <set>
#include <algorithm>

using namespace std;
#define MAX 9

int N, M;
int first[MAX];
int arr[MAX];
set<array<int, MAX>> s; 

void dfs(int num, int k) {
    if (k == M) {
        array<int, MAX> a;
        for (int i = 0; i < M; i++)
            a[i] = arr[i];
        s.insert(a);
    } else {
        for (int i = num; i < N; i++) {
            arr[k] = first[i];
            dfs(i, k + 1);
        }
    }
}

int main() {
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> first[i];

    sort(first, first + N);

    dfs(0, 0);

    for (const auto& a : s) {
        for (int i = 0; i < M; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}
