#include <iostream>

using namespace std;

int n, m;

int arr[10];


void recur(int level){
    if(level == m){
        for(int i = 0; i < m; i++){
            cout << arr[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i = 1; i <= n; i++){
        if(level > 0 && arr[level-1] > i) {continue;}
        arr[level] = i;
        recur(level+1);

    }
}

int main(){
    cin >> n >> m;

    recur(0);

}