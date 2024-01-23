#include <iostream>

using namespace std;

const int MAX_SIZE = 100001;
int min_heap[MAX_SIZE] = {0};
int idx = 1;

void insert(int val) {
  int temp_idx = idx++;
  min_heap[temp_idx] = val;

  while (temp_idx > 1) {
    int parent_idx = temp_idx / 2;
    if (min_heap[parent_idx] > min_heap[temp_idx]) {
      swap(min_heap[parent_idx], min_heap[temp_idx]);
      temp_idx = parent_idx;
    } else {
      break;
    }
  }
}

void heapify(int i) {
  int left = 2 * i;
  int right = 2 * i + 1;
  int smallest = i;

  if (left < idx && min_heap[left] < min_heap[smallest])
    smallest = left;
  if (right < idx && min_heap[right] < min_heap[smallest])
    smallest = right;

  if (smallest != i) {
    swap(min_heap[i], min_heap[smallest]);
    heapify(smallest);
  }
}

int removeMin() {
  if (idx == 1)
    return 0;

  int min_val = min_heap[1];
  min_heap[1] = min_heap[--idx];
  heapify(1);

  return min_val;
}

void printResult(int result) { cout << result << '\n'; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, temp;
  cin >> N;

  for (int i = 0; i < N; i++) {
    cin >> temp;
    if (temp == 0) {
      printResult(removeMin());
    } else {
      insert(temp);
    }
  }

  return 0;
}
