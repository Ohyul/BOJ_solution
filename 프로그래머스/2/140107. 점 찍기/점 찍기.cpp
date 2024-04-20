#include <string>
#include <vector>
#include <cmath>
#include <iostream>
typedef long long ll;
using namespace std;

ll solution(int k, int d) {
    ll answer =  d/k + 1;;
    for(ll i=0;i<d;i+=k){
        answer += (ll)sqrt(1LL*d*d - i*i)/k;
    }
    return answer;

}