#include <iostream>
#include <string>
#include <cstring>
#include <vector>
typedef long long ll;
using namespace std;


bool is_prime(ll val) {
    if (val <= 1) return false;
    if (val <= 3) return true;
    if (val % 2 == 0 || val % 3 == 0) return false;
    for (ll i = 5; i * i <= val; i += 6) {
        if (val % i == 0 || val % (i + 2) == 0)
            return false;
    }
    return true;
}


int solution(int n, int k) {
    int answer = -1;

    vector<char> modi, rev;
    answer = 0;

    while (n > 0) {
        int val = n % k;
        rev.push_back(val + '0');
        n /= k;
    }

    for (int i = 0; i < rev.size(); i++) {
        modi.push_back(rev[rev.size() - 1 - i]);
    }
    
    string prime;
    for (int i = 0; i < modi.size(); i++) {
        if (modi[i] == '0' && prime.size() > 0) {
            ll ret = stoll(prime);
            if(ret == 1){                
                prime = "";
                continue;
            }
            if (is_prime(ret) == 1) answer++;
            prime = "";
        }
        else if (modi[i] >= '1' && modi[i] <= '9') {
            prime.push_back(modi[i]);
        }
    }
    if(prime != ""){        
        ll ret = stoll(prime);
        if (ret != 1 && is_prime(ret) == 1) answer++;
        prime = "";
    }
    

    return answer;
}
