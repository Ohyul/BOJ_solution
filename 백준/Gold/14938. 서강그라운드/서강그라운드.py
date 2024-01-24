import sys
input = sys.stdin.readline

n, m, r = map(int, input().split())
road = [[(1e9)] * 101 for _ in range(101)]
node = list(map(int, input().split()))
for i in range(n):
    road[i+1][i+1] = 0
for i in range(r):
    row, column, dis = map(int, input().split())
    road[row][column] = dis
    road[column][row] = dis

for j in range(n+1):
    for i in range(n+1):
        for k in range(n+1):
            road[i][k] = min(road[i][k],road[i][j]+ road[j][k])


ans = [0 for _ in range(n)]
for i in range(n):
    for j in range(n):
        if road[i+1][j+1] <= m:
            ans[i]+=node[j]

print(max(ans))