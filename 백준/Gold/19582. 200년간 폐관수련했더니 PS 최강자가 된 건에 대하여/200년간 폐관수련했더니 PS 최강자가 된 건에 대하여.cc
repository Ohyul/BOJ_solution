#include <iostream>
#include <vector>

using namespace std;

struct Competition {
  int limit;
  int award;
};

int runWhole(int n, vector<Competition> &contests) {
  long long sum = 0;

  for (int i = 0; i < n - 2; i++) {
    if (sum + contests[i].award > contests[i + 1].limit) {
      return i + 1;
    }
    sum += contests[i].award;
  }

  return -1;
}

bool omitIdx(int n, vector<Competition> &contests, int idx) {
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    if (i == idx)
      continue;
    if (sum > contests[i].limit) {
      return false;
    }
    sum += contests[i].award;
  }
  return true;
}

bool omitLargest(int n, vector<Competition> &contests, int idx) {
  int largest_reward = -1;
  int largest_idx;

  for (int i = 0; i < idx; i++) {
    if (largest_reward < contests[i].award) {
      largest_idx = i;
      largest_reward = contests[i].award;
    }
  }

  return omitIdx(n, contests, largest_idx);
}

int main() {
  int n;
  cin >> n;

  vector<Competition> contests(n);

  for (int i = 0; i < n; i++) {
    cin >> contests[i].limit >> contests[i].award;
  }

  int result = runWhole(n, contests);

  if (result == -1 || omitIdx(n, contests, result) ||
      omitLargest(n, contests, result)) {
    cout << "Kkeo-eok";
  } else {
    cout << "Zzz";
  }
}