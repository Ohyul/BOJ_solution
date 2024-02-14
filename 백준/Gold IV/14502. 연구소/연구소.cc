#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Virus {
  int col, row;
  Virus(int _col, int _row) : col(_col), row(_row) {}
};

vector<vector<int>> arr;
vector<vector<bool>> is_visited;
queue<Virus> virus;
int maxi, ans;
int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

int spread(const Virus &v, vector<vector<bool>> &check) {
  int count_virus_range = 0;
  queue<Virus> q;
  q.push(v);
  check[v.row][v.col] = true;

  while (!q.empty()) {
    Virus cur = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int new_col = cur.col + dc[i];
      int new_row = cur.row + dr[i];

      if (new_col < 0 || new_col >= arr[0].size() || new_row < 0 ||
          new_row >= arr.size() || check[new_row][new_col] ||
          arr[new_row][new_col] != 0)
        continue;

      count_virus_range++;
      check[new_row][new_col] = true;
      q.push(Virus(new_col, new_row));
    }
  }
  return count_virus_range;
}

void permutation(int depth, int start_col, int start_row) {
  if (depth == 3) {
    int count_virus_range = 0;
    queue<Virus> q = virus;
    vector<vector<bool>> check = is_visited;

    while (!q.empty()) {
      count_virus_range += spread(q.front(), check);
      q.pop();
    }

    ans = max(ans, maxi - count_virus_range);
    return;
  }

  for (int row = start_row; row < arr.size(); ++row) {
    int new_col = (start_row == row) ? start_col : 0;

    for (int col = new_col; col < arr[0].size(); ++col) {
      if (is_visited[row][col] || arr[row][col] != 0)
        continue;
      is_visited[row][col] = true;
      arr[row][col] = 1;
      maxi--;
      permutation(depth + 1, col + 1, row);
      is_visited[row][col] = false;
      arr[row][col] = 0;
      maxi++;
    }
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  arr.resize(n, vector<int>(m));
  is_visited.resize(n, vector<bool>(m));
  maxi = n * m;

  for (int row = 0; row < n; ++row) {
    for (int col = 0; col < m; ++col) {
      cin >> arr[row][col];
      if (arr[row][col] == 0)
        continue;
      maxi--;
      if (arr[row][col] == 2) {
        virus.push(Virus(col, row));
      }
    }
  }

  permutation(0, 0, 0);
  cout << ans << "\n";

  return 0;
}