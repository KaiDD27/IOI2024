N, M, K, U = map(int, input().split())
parent = [-1] * N
for i in range(N - 1):
    a, b, w = map(int, input().split())
    parent[b] = (a, w)
trout_count = [0] * N
def add_trout(position, distance):
    while distance >= 0:
        trout_count[position] += 1
        if position == 0:
            break
        distance -= parent[position][1]
        position = parent[position][0]
for i in range(M):
    L, D = map(int, input().split())
    add_trout(L, D)
for i in range(K):
    query = input().split()
    if query[0] == 'Q':
        print(trout_count[int(query[1])])
    else:
        L, D = map(int, query[1:])
        add_trout(L, D)
