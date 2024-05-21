#include <iostream>
using namespace std;

int n;

void printStars(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = i, y = j;
            bool isBlank = false;
            while (x > 0 || y > 0) {
                if (x % 3 == 1 && y % 3 == 1) {
                    isBlank = true;
                    break;
                }
                x /= 3;
                y /= 3;
            }
            if (isBlank) {
                cout << " ";
            }
            else {
                cout << "*";
            }
        }
        cout << "\n";
    }
}

int main() {
    cin >> n;
    printStars(n);
}

