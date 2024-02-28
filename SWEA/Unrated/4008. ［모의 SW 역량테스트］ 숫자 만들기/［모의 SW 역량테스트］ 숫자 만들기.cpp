#include <iostream>
#include <algorithm>
using namespace std;

int n, maxi = -1e9, mini = 1e9;
int arr[14];
int arith[4];

int cases, each_case;

void dfs(int idx, int val, int sum, int sub, int mul, int div) {
	if (idx == n - 1) {
		maxi = max(maxi, val);
		mini = min(mini, val);
		return;
	}
	//sum
	if (sum >= 1)
		dfs(idx + 1, val + arr[idx + 1], sum - 1, sub, mul, div);
	//sub
	if (sub >= 1)
		dfs(idx + 1, val - arr[idx + 1], sum, sub - 1, mul, div);
	//mul
	if (mul >= 1)
		dfs(idx + 1, val * arr[idx + 1], sum, sub, mul - 1, div);
	//div
	if (div >= 1)
		dfs(idx + 1, val / arr[idx + 1], sum, sub, mul, div - 1);
}

int main() {
	cin >> cases;
	each_case = 1;
	while (each_case <= cases) {
		cin >> n;
		for (int i = 0; i < 4; i++) {
			cin >> arith[i];
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		int idx = 0;
		dfs(idx, arr[idx], arith[0], arith[1], arith[2], arith[3]);
		cout << "#" << each_case << " " << maxi - mini <<"\n";
		maxi = -1e9;
		mini = 1e9;
		each_case++;
	}
}