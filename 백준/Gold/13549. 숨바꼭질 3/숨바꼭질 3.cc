#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

struct State {
  int position; 
  int time;     

  State(int position, int time) : position(position), time(time) {}
};

int n, k;    
int minTime; 

const int MAX_POSITION = 100'000;
const int INF = 100'000;
int visited[MAX_POSITION + 1];
queue<State> q;

void bfs() {
  fill(visited, visited + MAX_POSITION + 1, INF);
  visited[n] = 0;
  q.push(State(n, 0));

  while (!q.empty()) {
    State current = q.front();
    q.pop();

    int np1 = current.position - 1;
    if (np1 >= 0 && visited[np1] > current.time + 1) {
      visited[np1] = current.time + 1;
      q.push(State(np1, visited[np1]));
    }

    int np2 = current.position + 1;
    if (np2 <= MAX_POSITION && visited[np2] > current.time + 1) {
      visited[np2] = current.time + 1;
      q.push(State(np2, visited[np2]));
    }

    int np3 = current.position * 2;
    if (np3 <= MAX_POSITION && visited[np3] > current.time) {
      visited[np3] = current.time;
      q.push(State(np3, visited[np3]));
    }
  }

  minTime = visited[k];
}

int main() {
  cin >> n >> k;

  if (n >= k)
    minTime = n - k;
  else
    bfs();

  cout << minTime << endl;
  return 0;
}