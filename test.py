def intersect(a, b):
 return max(0, min(a[3], b[3]) - max(a[2], b[2])) * max(0, min(a[1], b[1]) - max(a[0],
b[0]))
def area(a):
 return (a[3] - a[2]) * (a[1] - a[0])
N, A = map(int, input().split())
squares = []
for i in range(N):
 r, c = map(int, input().split())
 squares.append((max(0,c-A), c+A+1, max(0,r-A), r+A+1))
squares.sort()
res = 0
for i in range(N):
 res += area(squares[i])
 if i > 0:
 res -= intersect(squares[i], squares[i-1])
print(res)