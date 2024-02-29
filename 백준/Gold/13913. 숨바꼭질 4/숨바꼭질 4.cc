#include <iostream>
#include <queue>
#include <vector>
using namespace std;


struct Node {
    int val, time;
};

int n, m;
queue<Node> q;
vector<int> v;
int visited[100100], par[100100];

int main() {
    cin >> n >> m;

    Node start = { n, 0 };
    visited[start.val] = 1;
    par[start.val] = -1;
    q.push(start);

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        if (curr.val == m) {
            int node = m;
            v.push_back(node);
            cout << curr.time << "\n";
            while (true) {
                v.push_back(par[node]);
                node = par[node];
                if (node == -1)
                    break;
            }
            for (int i = v.size() - 2; i >= 0; i--) {
                cout << v[i] << " ";
            }
            break;
        }

        if (curr.val - 1 >= 0 && visited[curr.val - 1] == 0) {
            visited[curr.val - 1] = 1;
            par[curr.val - 1] = curr.val;
            q.push({ curr.val - 1, curr.time + 1});
        }

        if (curr.val + 1 <= 100000 && visited[curr.val + 1] == 0) {
            visited[curr.val + 1] = 1;
            par[curr.val + 1] = curr.val;
            q.push({ curr.val + 1, curr.time + 1});  
        }

        if (curr.val * 2 <= 100000 && visited[curr.val * 2] == 0) {
            visited[curr.val * 2] = 1;
            par[curr.val * 2] = curr.val;
            q.push({ curr.val * 2, curr.time + 1});
        }
    }
}
