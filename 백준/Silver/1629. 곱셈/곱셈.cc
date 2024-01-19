#include <iostream>

using namespace std;

long long a, b, c, k;

long long power(long long b) {

	//there's no exponent
	if (b == 0) return 1;
	//otherwise only one exponents
	if (b == 1) return a % c;

	k = power(b / 2) % c;
	if (b % 2 == 0) return k * k % c;
	return k * k % c * a % c;
}

int main() {

	cin >> a >> b >> c;
	cout << power(b);

	return 0;

}