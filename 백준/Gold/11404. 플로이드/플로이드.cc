#include <iostream>
using namespace std;

int arr[110][110];
int nodes, edges;
int row, col, val;
int maxi = 1e9;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> nodes >> edges;

  for (int row = 1; row <= nodes; row++) {
    for (int col = 1; col <= nodes; col++) {
      arr[row][col] = maxi;
      arr[row][row] = 0;
    }
  }
  for (int i = 0; i < edges; i++) {
    cin >> row >> col >> val;
    if (val > arr[row][col])
      continue;
    arr[row][col] = val;
  }

  for (int mid = 1; mid <= nodes; mid++) {
    for (int srt = 1; srt <= nodes; srt++) {
      for (int end = 1; end <= nodes; end++) {
        if (arr[srt][mid] == maxi || arr[srt][mid] == maxi)
          continue;
        if (arr[srt][end] > arr[srt][mid] + arr[mid][end]) {
          arr[srt][end] = arr[srt][mid] + arr[mid][end];
        }
      }
    }
  }
  for (int i = 1; i <= nodes; i++) {
    for (int j = 1; j <= nodes; j++) {
      if (arr[i][j] == maxi)
        arr[i][j] = 0;
      cout << arr[i][j] << " ";
    }
    cout << "\n";
  }
}