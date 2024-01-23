#include <iostream>
#include <algorithm> // Include the algorithm header for the min and max functions

using namespace std;

int arr[3][3];
int min_[3][3];
int max_[3][3];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 3; i++) {
        cin >> arr[0][i];
        min_[0][i] = arr[0][i];
        max_[0][i] = arr[0][i];
    }

    for (int i = 1; i < n; i++) {
        cin >> arr[i % 3][0] >> arr[i % 3][1] >> arr[i % 3][2];
        min_[(i % 3)][0] = min(min_[(i - 1) % 3][0] + arr[i % 3][0], min_[(i - 1) % 3][1] + arr[i % 3][0]);
        min_[(i % 3)][1] = min(min(min_[(i - 1) % 3][0] + arr[i % 3][1], min_[(i - 1) % 3][1] + arr[i % 3][1]), min_[(i - 1) % 3][2] + arr[i % 3][1]);
        min_[(i % 3)][2] = min(min_[(i - 1) % 3][1] + arr[i % 3][2], min_[(i - 1) % 3][2] + arr[i % 3][2]);

        max_[(i % 3)][0] = max(max_[(i - 1) % 3][0] + arr[i % 3][0], max_[(i - 1) % 3][1] + arr[i % 3][0]);
        max_[(i % 3)][1] = max(max(max_[(i - 1) % 3][0] + arr[i % 3][1], max_[(i - 1) % 3][1] + arr[i % 3][1]), max_[(i - 1) % 3][2] + arr[i % 3][1]);
        max_[(i % 3)][2] = max(max_[(i - 1) % 3][1] + arr[i % 3][2], max_[(i - 1) % 3][2] + arr[i % 3][2]);
    }

    cout << max({ max_[(n - 1) % 3][0], max_[(n - 1) % 3][1], max_[(n - 1) % 3][2] });
    cout << " " << min({ min_[(n - 1) % 3][0], min_[(n - 1) % 3][1], min_[(n - 1) % 3][2] });

    return 0;
}
