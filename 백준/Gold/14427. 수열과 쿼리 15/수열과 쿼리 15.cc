#include <iostream>
using namespace std;

struct Node {
    int idx, val;
};

int arr[100100];
Node segTree[100100 * 4];
int n, m, strIdx;

void init() {
    strIdx = 1; 
    while (strIdx < n) strIdx *= 2;

    for (int i = 0; i < n; i++) {
        segTree[i + strIdx].val = arr[i];
        segTree[i + strIdx].idx = i + 1;
    }
    for (int i = strIdx * 2 - 1; i >= n + strIdx; i--) {
        segTree[i].val = 1e9;
        segTree[i].idx = 1e9;
    }
    for (int i = strIdx - 1; i >= 1; i--) {
        if (segTree[i * 2].val == segTree[i * 2 + 1].val) {
            segTree[i].val = segTree[i * 2].val;
            segTree[i].idx = segTree[i * 2].idx;
        }
        else if (segTree[i * 2].val < segTree[i * 2 + 1].val) {
            segTree[i].val = segTree[i * 2].val;
            segTree[i].idx = segTree[i * 2].idx;
        }
        else {
            segTree[i].val = segTree[i * 2 + 1].val;
            segTree[i].idx = segTree[i * 2 + 1].idx;
        }
    }
}

void update(int idx, int tar) {

    segTree[idx + strIdx].val = tar;


    int i = (idx + strIdx) / 2; 
    while (i >= 1) {

        if (segTree[i * 2].val == segTree[i * 2 + 1].val) {
            segTree[i].val = segTree[i * 2].val;
            segTree[i].idx = segTree[i * 2].idx;
        }
        else if (segTree[i * 2].val < segTree[i * 2 + 1].val) {
            segTree[i].val = segTree[i * 2].val;
            segTree[i].idx = segTree[i * 2].idx;
        }
        else {
            segTree[i].val = segTree[i * 2 + 1].val;
            segTree[i].idx = segTree[i * 2 + 1].idx;
        }
        i /= 2;
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    init();

    cin >> m;
    for (int i = 0; i < m; i++) {
        int order;
        cin >> order;
        if (order == 2)
            cout << segTree[1].idx << "\n";
        else if (order == 1) {
            int tar, toVal;
            cin >> tar >> toVal;
            update(tar - 1, toVal);
        }
    }
}
