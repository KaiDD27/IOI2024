from bisect import bisect_left

N, M, K, U = map(int, input().split())
distance = [0] * N
for i in range(1, N):
    a, b, w = map(int, input().split())
    distance[i] = distance[i - 1] + w

trout_count = [0] * (N + 1)
for _ in range(M):
    L, D = map(int, input().split())
    left = bisect_left(distance, distance[L] - D)
    trout_count[left] += 1
    trout_count[L + 1] -= 1

for i in range(1, N + 1):
    trout_count[i] += trout_count[i - 1]

for _ in range(K):
    q = int(input().split()[1])
    print(trout_count[q])