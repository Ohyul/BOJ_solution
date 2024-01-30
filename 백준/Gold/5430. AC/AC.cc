#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

string func;
int n;

int cases;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> cases;
  while (cases > 0) {
    cin >> func >> n;
    int idx = 1;
    string arr;
    cin >> arr;
    string num;
    int input[100100];
    int arr_idx = 0;
    while (idx < arr.length()) {
      if (arr[idx] >= '0' && arr[idx] <= '9') {
        num.push_back(arr[idx]);
      } else if (arr[idx] == ',' || arr[idx] == ']') {
        if (num.length() > 0) {
          input[arr_idx++] = stoi(num);
          num = "";
        }
      }
      idx++;
    }
    int front = 0;
    int end = arr_idx - 1;
    int d_flag = 0;
    int is_reversed = 0;
    idx = 0;
    while (idx < func.length()) {
      if (func[idx] == 'D') {
        d_flag = 1;
        if (is_reversed == 0) {
          front++;
        } else if (is_reversed == 1) {
          end--;
        }
      } else if (func[idx] == 'R') {
        is_reversed = (is_reversed + 1) % 2;
      }
      idx++;
    }

    if (front > end + 1 && d_flag == 1) {
      cout << "error\n";
    } else {
      cout << "[";
      if (front <= end) {
        if (is_reversed == 0) {
          for (int i = front; i <= end - 1; i++) {
            cout << input[i] << ",";
          }
          cout << input[end];
        } else if (is_reversed == 1) {
          for (int i = end; i >= front + 1; i--) {
            cout << input[i] << ",";
          }
          cout << input[front];
        }
      }
      cout << "]\n";
    }
    cases--;
  }
}