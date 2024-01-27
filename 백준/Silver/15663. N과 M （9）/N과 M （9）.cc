#include <iostream>

using namespace std;
int n , m;
int arr[10];
bool used[10];
int path[10];

void recur(int level){
    if(level == m){
        for(int i = 0; i < m; i++){
            cout << path[i] << " ";
        }
        cout << "\n";
        return;
    }
    int prev = 0;
    for(int i = 0; i < n; i++){
        if(used[i] == true) continue;
        if(prev == arr[i]) continue;
        used[i] = true;
        path[level] = arr[i];
        prev = arr[i];
        recur(level + 1);
        used[i] = false;
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            if(arr[j] > arr[i]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
    recur(0);
}