n = int(input())
for i in range(n):
    row = input()
    a = 0
    a += (int(c.isdigit()) for c in row)
    print(a) 