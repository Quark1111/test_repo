class Graph:
    def __init__(self, directed):
        self.directed = directed
        
    def DFS(self, Top, visited):
        visited.append(Top)
        
        for Next in self.directed[Top]:
            if Next not in visited:
                self.DFS(Next, visited)

        return visited
    
    def __iter__(self):
        self.visited = []
        self.stack = []

        if self.directed:
            start_vertex = list(self.directed.keys())[0]
            self.stack.append(start_vertex)

        return self
    
    def __next__(self):
        while self.stack:
            vertex = self.stack.pop()

            if vertex not in self.visited:
                self.visited.append(vertex)

                for neighbor in self.directed[vertex]:
                    if neighbor not in self.visited:
                        self.stack.append(neighbor)

                return vertex
        
Tops = int(input("введите количество вершин: "))
mas = []

directed = dict()
for i in range(Tops):
    top = input("Введите вершину: ")
    neighbors = input("Введите её соседей: ").split()
    directed[top] = neighbors    

graph = Graph(directed)
print(graph.directed)
iterator = iter(graph)
print(graph.DFS(next(iterator), []))
