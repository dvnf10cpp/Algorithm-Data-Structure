class Node : 
    def __init__(self, value) -> None:
        self.next = None
        self.value = value
    

a = Node(10)
b = Node(20)
a.next = b