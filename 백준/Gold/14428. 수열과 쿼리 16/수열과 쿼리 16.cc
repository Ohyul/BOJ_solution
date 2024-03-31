#include<iostream>
#include <vector>
#include <climits>
using namespace std;

struct Node {
    int val, idx;
};

int arr[100010];
Node segTree[100010 * 4];
int strIdx;
int n, q;

void init() {
    strIdx = 2;
    while (strIdx < n) strIdx *= 2;
    for (int i = 0; i < n; i++) {
        segTree[i + strIdx].val = arr[i];
        segTree[i + strIdx].idx = i + 1;
    }
    for (int i = n + strIdx; i < strIdx << 1; i++) {
        segTree[i].val = INT_MAX;
        segTree[i].idx = -1;
    }
    for (int i = strIdx - 1; i >= 1; i--) {
        if (segTree[i << 1].val > segTree[i << 1 | 1].val) {
            segTree[i].val = segTree[i << 1 | 1].val;
            segTree[i].idx = segTree[i << 1 | 1].idx;
        }
        else if (segTree[i << 1].val < segTree[i << 1 | 1].val) {
            segTree[i].val = segTree[i << 1].val;
            segTree[i].idx = segTree[i << 1].idx;
        }
        else if (segTree[i << 1].val == segTree[i << 1 | 1].val) {
            segTree[i].val = segTree[i << 1].val;
            segTree[i].idx = segTree[i << 1].idx;
        }
    }
}

void query(int from, int to) {
    int min_idx = -1;
    int mini = INT_MAX;
    from += strIdx;
    to += strIdx;
    for (from, to; from != to; from >>= 1, to >>= 1) {
        if (from & 1) {
            if (mini > segTree[from].val) {
                mini = segTree[from].val;
                min_idx = segTree[from].idx;
            }
            else if (mini == segTree[from].val) {
                mini = segTree[from].val;
                min_idx = min(min_idx, segTree[from].idx);
            }
            from++;
        }
        if (to & 1) {
            to--;
            if (mini > segTree[to].val) {
                mini = segTree[to].val;
                min_idx = segTree[to].idx;
            }
            else if (mini == segTree[to].val) {
                mini = segTree[to].val;
                min_idx = min(min_idx, segTree[to].idx);
            }
        }
    }
    cout << min_idx << "\n";
}

void update(int idx, int val) {
    arr[idx] = val;
    int i = idx + strIdx;
    segTree[i].val = val;
    i >>= 1;
    while (i >= 1) {
        int leftChildIdx = i << 1;
        int rightChildIdx = (i << 1) | 1;
        if (segTree[leftChildIdx].val > segTree[rightChildIdx].val) {
            segTree[i].val = segTree[rightChildIdx].val;
            segTree[i].idx = segTree[rightChildIdx].idx;
        }
        else if (segTree[leftChildIdx].val < segTree[rightChildIdx].val) {
            segTree[i].val = segTree[leftChildIdx].val;
            segTree[i].idx = segTree[leftChildIdx].idx;
        }
        else {
            segTree[i].val = segTree[leftChildIdx].val;
            segTree[i].idx = min(segTree[leftChildIdx].idx, segTree[rightChildIdx].idx);
        }
        i >>= 1;
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
    cin >> q;
    for (int i = 0; i < q; i++) {
        int inst;
        cin >> inst;
        if (inst == 2) {
            int from, to;
            cin >> from >> to;
            query(from - 1, to);
        }
        if (inst == 1) {
            int idx, val;
            cin >> idx >> val;
            update(idx - 1, val);
        }
    }
    return 0;
}
