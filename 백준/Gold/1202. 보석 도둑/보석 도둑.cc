#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

struct Jewel {
    int weight, val;
};

// Comparator function for sorting jewels based on weight
bool compare(Jewel l, Jewel r) {
    return l.weight < r.weight;
}

int n, k;
ll ans;
vector<Jewel> jewels;
vector<ll> bags;
priority_queue<ll> q;
int idx;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    jewels.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> jewels[i].weight >> jewels[i].val; 
    }
    sort(jewels.begin(), jewels.end(), compare);

    bags.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> bags[i];
    }
    sort(bags.begin(), bags.end());

    idx = 0;
    ans = 0; 
    for (int i = 0; i < k; i++) {
        while (idx < n && jewels[idx].weight <= bags[i]) {
            q.push(jewels[idx].val);
            idx++;
        }
        if (!q.empty()) {
            ans += q.top();
            q.pop();
        }
    }
    cout << ans;
}