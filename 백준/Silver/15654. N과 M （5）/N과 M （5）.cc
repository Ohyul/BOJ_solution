#include <iostream>

using namespace std;

int arr[10];
int ans[10];
bool used[10];
int n, m;

void recur(int level) {
    if (level == m) {
        for (int i = 0; i < m; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        if (used[i] == true) {
            continue;
        }
        used[i] = true;
        ans[level] = arr[i];
        recur(level + 1);
        used[i] = false;
    }
}


int main(){
    fill(begin(arr), end(arr), 20000);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> arr[i]; 
    }
    for(int i = 0; i < n; i++){
        int temp = 0;
        for(int j = 0; j <= i; j++){
            if(arr[i] < arr[j] && arr[i]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    recur(0);
}