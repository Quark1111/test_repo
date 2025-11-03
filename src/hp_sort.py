def heap_sort(ms):
    mas = ms.copy()
    mas_heap = [0] * (len(mas) + 1)
    def f(c0, c1, ln):
        if c1 <= ln:
            if mas_heap[c0] > mas_heap[c1]:
                return c1
        return 0
    for i in range(len(mas)):
        ind = i + 1
        mas_heap[ind] = mas[i]
        while ind // 2 > 0 and mas_heap[ind] < mas_heap[ind // 2]:
            mas_heap[ind], mas_heap[ind // 2] = mas_heap[ind // 2], mas_heap[ind]
            ind //= 2
    x = 0
    ln = len(mas)
    l = ln
    while x < l:
        x += 1
        mas[x - 1] = mas_heap[1]
        mas_heap[1], mas_heap[ln] = mas_heap[ln], mas_heap[1]    
        ind = 1
        ln -= 1
        while ind <= ln:
            heap1 = f(ind, ind * 2, ln)
            heap2 = f(ind, ind * 2 + 1, ln)
            if heap1 + heap2 == 0:
                break
            elif heap1 and heap2:
                if mas_heap[heap1] < mas_heap[heap2]:
                    mas_heap[ind], mas_heap[heap1] = mas_heap[heap1], mas_heap[ind]
                    ind = heap1
                else:
                    mas_heap[ind], mas_heap[heap2] = mas_heap[heap2], mas_heap[ind]
                    ind = heap2
            elif heap1:
                mas_heap[ind], mas_heap[heap1] = mas_heap[heap1], mas_heap[ind]
                ind = heap1
            else:
                mas_heap[ind], mas_heap[heap2] = mas_heap[heap2], mas_heap[ind]
                ind = heap2
    return mas