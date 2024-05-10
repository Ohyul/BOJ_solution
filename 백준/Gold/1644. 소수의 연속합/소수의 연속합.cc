#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int n, cnt, sum, str, dst;
vector<int> primes;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    vector<int> isPrime(n + 1, 1);

    for (int i = 2; i <= sqrt(n); ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    while (str < primes.size()) {
        if (sum < n && dst < primes.size()) {
            sum += primes[dst++];
        }
        else {
            if (sum == n) cnt++;
            sum -= primes[str++];
        }
    }

    cout << cnt;
}
