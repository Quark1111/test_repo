class HashTable:
    def __init__(self):
        self.table = []
        self.size = 128
        for i in range(self.size):
            self.table.append([])
        
    def Hash(self, key):
        resultHash = 0
        for i in range(len(key)):
            resultHash += ord(key[i])
        return resultHash % self.size

    def put(self, key, value):
        index = self.Hash(key)
        if self.table[index] == []:
            self.table[index].append([key, value])
        else:
            flag = 1
            for i in range(len(self.table[index])):
                if self.table[index][i][0] == key:
                    flag = 0
                    self.table[index][i][1] = value
                    break

            if flag:
                self.table[index].append([key, value])
                
    def get(self, key):
        index = self.Hash(key)
        i = 0
        while i < len(self.table[index]):
            if self.table[index][i][0] == key:
                return self.table[index][i][1]
            i += 1
        
        raise Exception("Не существующий ключ")

    def remove(self, key):
        index = self.Hash(key)
        i = 0
        flag = 1
        while i < len(self.table[index]):
            if self.table[index][i][0] == key:
                self.table[index].pop(i)
                flag = 0
                break
            i += 1
        if flag:
            raise Exception("Не существующий ключ")
