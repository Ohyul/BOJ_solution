#include <iostream>

using namespace std;

int n, m;
int arr[10];
int path[10];

void recur(int level){
    if(level == m){
        for(int i = 0; i < m; i++){
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0; i < n; i++){
        if(level >= 1){
            if(path[level-1] > arr[i]) continue;
        }
        path[level] = arr[i];
        recur(level + 1);
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i ; j++){
            if(arr[i] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    recur(0);
}