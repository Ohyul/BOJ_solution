#include <iostream>
using namespace std;

int n, m;

int main(){
    cin >> n >> m;
    if( n > 0 && m > 0) cout << "1";
    else if( n < 0 && m > 0) cout << "2";
    else if( n < 0 && m < 0) cout << "3";
    else cout << "4";
}