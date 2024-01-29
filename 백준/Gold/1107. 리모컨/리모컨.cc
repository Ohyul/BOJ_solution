#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> broken_btn(10, 0);

bool is_button_working(int n) {
  string str_n = to_string(n);
  for (char digit : str_n) {
    if (broken_btn[digit - '0'] == 1) {
      return false;
    }
  }
  return true;
}

int press_button_and_move(int target) {
  int cnt = abs(target - 100);

  for (int i = 0; i <= 1000000; ++i) {
    if (is_button_working(i)) {
      int second_cnt = abs(target - i) + to_string(i).length();
      cnt = min(cnt, second_cnt);
    }
  }

  return cnt;
}

int main() {
  int target, m;
  cin >> target >> m;

  for (int i = 0; i < m; ++i) {
    int btn_number;
    cin >> btn_number;
    broken_btn[btn_number] = 1;
  }

  int cnt_method1 = press_button_and_move(target);

  cout << cnt_method1;

  return 0;
}
