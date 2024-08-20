from math import ceil, sqrt
N, M = map(int, input().split())
cities = [int(input().split()[0]) for _ in range(N)]
path = list(map(int, input().split()))
def cost(a, b):
 return abs(cities[a] - cities[b])
sorted_order = list(range(N))
sorted_order.sort(key = lambda x: cities[x])
position_in_sorted_order = [0] * N
for i in range(N):
 position_in_sorted_order[sorted_order[i]] = i
money = [0] * M
for i in range(M-2, -1, -1):
 money[i] = money[i+1] + cost(path[i], path[i+1])
for i in range(M):
 sorted_idx = position_in_sorted_order[path[i]]
 #Find left bound (b)
 bl, bu = 0, sorted_idx
 while bl != bu:
  m = (bl + bu) // 2
  if cost(sorted_order[m], path[i]) > money[i]:
   bl = m + 1
  else:
   bu = m
 b = bl
 #Find right bound (c)
 cl, cu = sorted_idx, N-1
 while cl != cu:
  m = (cl + cu) // 2 + 1
  if cost(sorted_order[m], path[i]) > money[i]:
   cu = m - 1
  else:
   cl = m
 c = cl
 print(c - b, end = " ")
print()