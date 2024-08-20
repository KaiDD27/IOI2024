from math import ceil, sqrt

N, M = map(int, input().split())
cities = [tuple(map(int, input().split())) for _ in range(N)]
path = list(map(int, input().split()))

def cost(a, b):
 return ceil(sqrt((cities[a][0] - cities[b][0]) ** 2 + (cities[a][1] - cities[b][1]) ** 2))

money = [0] * M
for i in range(M-2, -1, -1):
 money[i] = money[i+1] + cost(path[i], path[i+1])

for i in range(M):
 count = 0
 for j in range(N):
  if j == path[i]:
   continue
  if cost(path[i], j) <= money[i]:
   count += 1
 print(count, end=" ")
print()