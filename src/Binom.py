class BinomialTreeNode:
    def __init__(self, key, value=None):
        self.key = key          
        self.value = value      
        self.degree = 0         
        self.parent = None
        self.child = None       
        self.sibling = None

class BinomialHeap:
    def __init__(self):
        self.head = None  
    
    def getMinimum(self):
        if self.head is None:
            return None
        
        min_node = self.head
        current = self.head.sibling
        
        while current:
            if current.key < min_node.key:
                min_node = current
            current = current.sibling
        
        return min_node
    
    def merge(self, other_heap):
        self.head = self._merge_heaps(self.head, other_heap.head)
        
        if self.head is None:
            return
        
        prev = None
        current = self.head
        next_node = current.sibling
        
        while next_node:
            if (current.degree != next_node.degree or 
                (next_node.sibling and next_node.sibling.degree == current.degree)):
                prev = current
                current = next_node
            else:
                if current.key <= next_node.key:
                    current.sibling = next_node.sibling
                    child.parent = parent
                    child.sibling = parent.child
                    parent.child = child
                    parent.degree += 1
                else:
                    if prev:
                        prev.sibling = next_node
                    else:
                        self.head = next_node
                    next_node.parent = current
                    current.sibling = next_node.child
                    next_node.child = current
                    next_node.degree += 1
                    current = next_node
            
            next_node = current.sibling
    
    def insert(self, key, value=None):
        new_heap = BinomialHeap()
        new_node = BinomialTreeNode(key, value)
        new_heap.head = new_node
        self.merge(new_heap)
        return new_node
    
    def extractMin(self):
        if self.head is None:
            return None
        
        min_node = self.head
        min_prev = None
        prev = None
        current = self.head
        
        while current:
            if current.key < min_node.key:
                min_node = current
                min_prev = prev
            prev = current
            current = current.sibling
        
        if min_prev:
            min_prev.sibling = min_node.sibling
        else:
            self.head = min_node.sibling
        
        new_heap = BinomialHeap()
        
        child = min_node.child
        while child:
            next_child = child.sibling
            child.sibling = new_heap.head
            child.parent = None
            new_heap.head = child
            child = next_child
        
        self.merge(new_heap)
        
        return min_node
    
    def decreaseKey(self, node, new_key):
        if new_key > node.key:
            raise ValueError("Новый ключ должен быть меньше текущего")
        
        node.key = new_key
        parent = node.parent
        while parent and node.key < parent.key:
            node.key, parent.key = parent.key, node.key
            node.value, parent.value = parent.value, node.value
            
            node = parent
            parent = node.parent
    
    def delete(self, node):
        self.decreaseKey(node, float('-inf'))
        return self.extractMin()
    
    def _merge_heaps(self, head1, head2):
        if head1 is None:
            return head2
        if head2 is None:
            return head1
        
        result = None
        current = None
        
        if head1.degree <= head2.degree:
            result = head1
            head1 = head1.sibling
        else:
            result = head2
            head2 = head2.sibling
        
        current = result
        
        while head1 and head2:
            if head1.degree <= head2.degree:
                current.sibling = head1
                head1 = head1.sibling
            else:
                current.sibling = head2
                head2 = head2.sibling
            current = current.sibling
        
        if head1:
            current.sibling = head1
        else:
            current.sibling = head2
        
        return result
