def gcd(a, b, x, y):
    a1 = 1
    b1 = 0
    a2 = 0
    b2 = 1
    ms = [[a1, b1]]
    cnt = 0
    while b != 0:
        g = max(a, b) // min(a, b)
        if cnt % 2 == 0:
            ms.append([a1 - g * a2, b1 - g * b2])
            a1 = a1 - g * a2
            b1 = b1 - g * b2
        else:
            ms.append([a2 - g * a1, b2 - g * b1])
            a2 = a2 - g * a1
            b2 = b2 - g * b1
        a, b = b, a % b
        cnt += 1
    
    if ms[-2][1] < 0:
        ms[-2][0], ms[-2][1] = ms[-2][1], ms[-2][0]
    if x * ms[-2][0] + y * ms[-2][1] != a:
        x, y = y, x
    print(ms[-2][0], '*', x, '+', ms[-2][1], '*', y, '=', a)
ms=list(map(int, input().split()))
gcd(max(ms[0], ms[1]), min(ms[0], ms[1]), max(ms[0], ms[1]), min(ms[0], ms[1]))
