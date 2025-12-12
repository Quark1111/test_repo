def heapify(mas, n, i):
        largest = i
        left = i*2 + 1
        right = i*2 + 2

        if left < n and mas[largest] < mas[left]:
            largest = left
        if right < n and mas[largest] < mas[right]:
            largest = right

        if largest != i:
            mas[i], mas[largest] = mas[largest], mas[i]
            heapify(mas, n, largest)
def HeapSort(mas):
    n = len(mas)
    
    for i in range(n // 2 - 1, -1, -1):
        heapify(mas, n, i)

    for i in range(n - 1,  -1, -1):
        mas[0], mas[i] = mas[i], mas[0]
        heapify(mas, i, 0)

    return mas

