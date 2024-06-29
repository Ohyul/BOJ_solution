#include <iostream>
#include <cmath>
using namespace std;

int T;
int x, y, n;

int main() {
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> x >> y;
        y -= x;
        x = 0;
        n = (int)sqrt(y);
        int nextMove = 2 * n - 1;
        y -= n * n;
        nextMove += (y / n) + (y % n == 0 ? 0 : 1);
        cout << nextMove << "\n";
    }
}