#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Include for INT_MAX and INT_MIN
using namespace std;

struct Node {
    int mini, maxi;
};

int n, m;
int arr[100100];
Node segTree[100100 * 4];
int strIdx;

void init() {
    strIdx = 1;
    while (strIdx < n) {
        strIdx *= 2;
    }
    for (int i = 0; i < n; i++) {
        segTree[i + strIdx].mini = arr[i];
        segTree[i + strIdx].maxi = arr[i];
    }
    for (int i = n + strIdx; i < strIdx * 2; i++) {
        segTree[i].mini = INT_MAX;
        segTree[i].maxi = INT_MIN;
    }
    for (int i = strIdx - 1; i != 0; i--) { 
        segTree[i].mini = min(segTree[i << 1].mini, segTree[i << 1 | 1].mini);
        segTree[i].maxi = max(segTree[i << 1].maxi, segTree[i << 1 | 1].maxi);
    }
}


void query(int from, int to) {
    int mini = INT_MAX, maxi = INT_MIN;
    for (from += strIdx, to += strIdx + 1; from < to; from >>= 1, to >>= 1) { 
        if (from & 1) {
            mini = min(mini, segTree[from].mini);
            maxi = max(maxi, segTree[from].maxi);
            from++;
        }
        if (to & 1) {
            to--;
            mini = min(mini, segTree[to].mini);
            maxi = max(maxi, segTree[to].maxi);
        }
    }
    cout << mini << " " << maxi << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    init();

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        query(l - 1, r - 1);
    }
}