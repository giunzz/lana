a = []
for i in range(0, int(input('Nhap n: '))):
    a.append((int(input('Nhap so thu %d: ' % i))))
for i in a:
    print('So thu %d: %d\n' % i, a[i])