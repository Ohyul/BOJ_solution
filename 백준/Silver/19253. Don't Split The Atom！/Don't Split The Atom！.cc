#include <iostream>
using namespace std;

int Z, N;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> Z;

    while (Z--) {
        cin >> N;
        if (N % 2 == 0) cout << "A\n";
        else cout << "B\n";
    }
}
