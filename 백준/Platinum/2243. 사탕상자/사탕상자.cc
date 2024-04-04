#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

const int MAX_SIZE = 1000010;

int n;
ll arr[MAX_SIZE], segTree[MAX_SIZE * 4];
int inst, tar, val;
int strIdx;

void init() {
    strIdx = 1;
    while (strIdx < MAX_SIZE) strIdx <<= 1;
    for (int i = 0; i < MAX_SIZE; i++) {
        segTree[i + strIdx] = arr[i];
    }
    for (int i = strIdx - 1; i >= 1; i--) {
        segTree[i] = segTree[i << 1] + segTree[i << 1 | 1];
    }
}

void update(int tar, int val) {
    arr[tar] += val;
    tar += strIdx;
    segTree[tar] += val;
    tar >>= 1;
    while (tar >= 1) {
        segTree[tar] = segTree[tar << 1] + segTree[tar << 1 | 1];
        tar >>= 1;
    }
}

void pop(int tar) {
    int idx = 1;
    while (idx < strIdx) {
        if (tar <= segTree[idx << 1]) {
            idx <<= 1;
        }
        else {
            tar -= segTree[idx << 1];
            idx = (idx << 1) | 1;
        }
    }
    cout << idx - strIdx + 1 << "\n";
    segTree[idx]--;
    update(idx - strIdx, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    init();

    for (int i = 0; i < n; i++) {
        cin >> inst;
        if (inst == 1) {
            cin >> tar;
            pop(tar);
        }
        else if (inst == 2) {
            cin >> tar >> val;
            update(tar - 1, val);
        }
    }
}
