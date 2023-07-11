"""
Linked list merupakan struktur data linear dimana setiap element dalam list termasuk ke dalam objek yang terpisah
yang dipanggil sebagai node.
Sebuah model/objek node mengandung 2 informasi variabel, nilai item yang disimpan dan referensi ke node selanjutnya.
Node pertama dalam linked list dipanggil dengan kata head, dan yang terakhir dipanggil dengan kata tail.
"""

# OOP Knowledge Required
class Node : 
    """
    Object for storing a single node in linked list
    """
    data = None;
    next = None;

    def __init__(self, data) -> None:
        self.data = data;

    def __str__(self) -> str : 
        return "%s" % str(self.data);

# Singly Linked List
class SinglyLinkedList : 
    def __init__(self) -> None:
        self.head : Node = None;
        self.size : int = 0; # Make the size to be read at O(1)

    def isEmpty(self) -> bool :
        return self.head == None;

    def sizeOf(self) -> int :
        # runs in linear time
        # return number of nodes in sll
        current : Node = self.head;
        count : int = 0;
        while (current != None) :
            count += 1;
            current = current.next;

        return count;

    def add_next(self, value : any) -> None : 
        # Add next reference to linked list
        new_node : Node = Node(value);
        if (self.head == None) :
            self.head = new_node;
            self.size += 1;
            return;

        current : Node = self.head;
        while(current.next != None) :
            current = current.next;

        current.next = new_node;
        self.size += 1;

    def append(self, value : any) -> None : 
        # Append new node at the beginning of the linked list
        new_node : Node = Node(value);
        new_node.next : Node = self.head;
        self.head = new_node;
        self.size += 1;
    
    def insert(self, value : any, index : int) -> None : 
        # Insert new node at any index
        # Function takes linear time O(n)
        # Try to visualize if you dont understand
        if(index == 0) :
            self.append(value);
            return;
    
        current : Node = self.head;
        new_node : Node = Node(value);
        while (index > 1) :
            current = current.next;
            index -= 1;

        prev_node : Node = current;
        next_node : Node = current.next;

        prev_node.next = new_node;
        new_node.next = next_node;
        self.size += 1;

    def remove(self, key : any) -> Node : 
        # Removes node containing data that matches key
        # Returns the node or None (null)
        # Takes linear time
        current : Node = self.head;
        previous : Node = None;
        found : bool = False;
        while (current != None and not found) :
            if (current.data == key and current is self.head) :
                found = True;
                self.head = current.next;
            elif (current.data == key) :
                found = True;
                previous.next = current.next;
            else : 
                previous = current;
                current = current.next;
        if (found) : self.size -= 1;
        return current;

    # Make function that remove at index and read at index
    def removeAt(self, index : int) -> Node :
        # Removes node that matches the index
        # Returns the node or None (null)
        # O(n) time    
        print(self.size);
        if(index < 0 or index > self.size - 1) :
            return None;
    
        current : Node = self.head;
        if (index == 0) :
            self.head = self.head.next;
            return current;

        previous : Node = None;
        found : bool = False;
        while(index > 0) :
            previous = current;
            current = current.next;
            index -= 1;
        
        previous.next : Node = current.next;
        return current;

    def get(self, index : int) -> Node : 
        if (index < 0 or index > self.size) :
            raise IndexError("Index out of range");
        current : Node = self.head;
        while (current != None and index > 0) :
            current = current.next;
            index -= 1;
        return current;
        
    def search(self, key : any) -> Node :
        # Searching for the first node containing data that matches the parameter (key)
        current : Node = self.head;
        while (current != None) :
            if (current.data == key) :
                return current;
            current = current.next;

        return None; # return None (null) if it doesnt exist

    def exist(self, key : any) -> bool :
        if (self.search(key) != None) :
            return True;
        return False;

    # below is get method implementation using []
    def __getitem__(self, index) :
        if (index < 0 or index > self.size) :
            raise IndexError("Index out of range");
        current = self.head;
        while (current != None and index > 0) :
            current = current.next;
            index -= 1;
        return current;

    def __str__(self) -> None : 
        info : list = [];
        current = self.head;
        while (current != None) :
            if (current is self.head) :
                info.append("[Head: %s]" % str(current.data));
            elif (current.next is None) :
                info.append("[Tail: %s]" % str(current.data));
            else :
                info.append("[%s]" % str(current.data));
            current = current.next;
        
        return '->'.join(info);
        


# Class for Demo functions
class Demo : 
    def demo_node() -> None : 
        node_1 : Node = Node(10);
        node_2 : Node = Node("Me");
        print(node_1);
        print(node_2);

        node_1.next = node_2;
        print(node_1.next);

    def demo_sll() -> None : 
        sll = SinglyLinkedList();
        
        sll.add_next(5);
        sll.add_next(10);
        print("Size: ", sll.sizeOf());

        print(sll);
        sll.append(3);
        print(sll);
        print(sll.exist(10));

        sll.insert(4,1);
        sll.insert(2,0);
        print(sll);

        sll.removeAt(10);
        print(sll);
        print(sll.get(1));
        print(sll[2]);

Demo.demo_node(); 
print("==================================")
Demo.demo_sll(); 