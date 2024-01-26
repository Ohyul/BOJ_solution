#include <iostream>
#include <cmath>

using namespace std;

const int MAX_CHICKEN_HOUSES = 15;
const int MAX_HOUSES = 2520;
int n, m;
int chickenX[MAX_CHICKEN_HOUSES];
int chickenY[MAX_CHICKEN_HOUSES];
int houseX[MAX_HOUSES];
int houseY[MAX_HOUSES];
int permutation[MAX_CHICKEN_HOUSES];
int chickenCount = 0;
int houseCount = 0;
int result = 1e9;

void combination(int count, int next) {
    if (count == m) {
        int temp = 0;
        for (int i = 0; i < houseCount; i++) {
            int minDistance = 1e9;
            for (int j = 0; j < m; j++) {
                int distance = abs(houseX[i] - chickenX[permutation[j]]) + abs(houseY[i] - chickenY[permutation[j]]);
                minDistance = min(minDistance, distance);
            }
            temp += minDistance;
        }
        if (result > temp)
            result = temp;
    } else {
        for (int i = next; i < chickenCount; i++) {
            permutation[count] = i;
            combination(count + 1, i + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    int value;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> value;
            if (value == 2) {
                chickenX[chickenCount] = i;
                chickenY[chickenCount] = j;
                chickenCount++;
            } else if (value == 1) {
                houseX[houseCount] = i;
                houseY[houseCount] = j;
                houseCount++;
            }
        }
    }
    combination(0, 0);
    cout << result << '\n';
    return 0;
}
