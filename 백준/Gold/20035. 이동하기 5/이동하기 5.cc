#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int N, M;
int AMaxi = -1, ASum = 0;
int BMaxi = -1, Bsum = 0;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    vector<int> v;
    v.reserve(N);

    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        ASum += num;
        if (num > AMaxi) {
            AMaxi = num;
            v.clear();
            v.push_back(i);
        }
        else if (num == AMaxi) {
            v.push_back(i);
        }
    }

    vector<int> Barr(M);

    for (int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        Barr[i] = num;
        Bsum += num;
        if (num > BMaxi) {
            BMaxi = num;
        }
    }

    long long sum = 0;
    sum += (long long)(ASum + AMaxi * (M - 1)) * 1'000'000'000;

    if (v.size() == 1)
        sum += Bsum + Barr[0] * (v[0]) + Barr[M - 1] * (N - v[0] - 1);
    else
        sum += Bsum + Barr[0] * (v[0]) + BMaxi * (v[v.size() - 1] - v[0]) + (N - v[v.size() - 1] - 1) * Barr[M - 1];

    cout << sum;
}
