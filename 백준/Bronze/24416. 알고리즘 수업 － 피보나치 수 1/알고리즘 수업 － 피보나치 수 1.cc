#include <iostream>
using namespace std;
typedef long long ll;

ll arr[41];
int N; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
    cout.tie(0);
    
    cin >> N;

	arr[1] = arr[2] = 1;
	for (int i = 3; i < 41; i++){
        arr[i] = arr[i - 1] + arr[i - 2];
    } 
	cout << arr[N] << " " << N - 2;
}