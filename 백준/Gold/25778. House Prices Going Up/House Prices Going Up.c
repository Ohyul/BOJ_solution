#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 1000000
long long tree[MAX_N * 4]; // 세그먼트 트리

// 세그먼트 트리 노드 갱신 함수
void update(int node, int start, int end, int idx, int val) {
  if (idx < start || idx > end)
    return;
  tree[node] += val;
  if (start != end) {
    int mid = (start + end) / 2;
    update(node * 2, start, mid, idx, val);
    update(node * 2 + 1, mid + 1, end, idx, val);
  }
}

// 세그먼트 트리 구간합 쿼리 함수
long long query(int node, int start, int end, int left, int right) {
  if (right < start || end < left)
    return 0;
  if (left <= start && end <= right)
    return tree[node];
  int mid = (start + end) / 2;
  return query(node * 2, start, mid, left, right) +
         query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
  int N = 0; //집의 개수
  scanf("%d", &N);
  int HS[N];
  for (int i = 1; i <= N; i++) {
    scanf("%d", &HS[i]); //가격 입력
    update(1, 1, N, i, HS[i]);
  }
  int T = 0; //트랜젝션의 수
  scanf("%d", &T);
  T *= 2;
  char op;
  int A, B;
  // int sum = 0;
  // int tran[T][3]; // 트랜젝션 입력
  int k = 0;
  while (k < T) {
    op = 0;
    A = 0;
    B = 0;
    scanf("%c %d %d", &op, &A, &B);
    if (op == 'R') {
      printf("%lld\n", query(1, 1, N, A, B)); // 구간합 쿼리
      // printf("%d\n", Sum(A, B, 1, 1, N - 1));
      /*
        sum = 0;
        for (int l = A; l <= B; l++) {
          sum += HS[l - 1];

      }
      printf("%d\n", sum);
      */
    } else {
      // HS[A - 1] += B;
      update(1, 1, N, A, B); // 노드 갱신
      HS[A] = B;
    }
    k++;
  }
  return 0;
}

// void update(int house_num, int cost, int arr[]) { arr[house_num - 1] += cost;
// }

void retrieve(int start, int end, int arr[]) {
  int sum = 0; // 부분합 입력
  for (int i = start; i <= end; i++) {
    sum += arr[i - 1];
  }
  printf("%d\n", sum);
}
