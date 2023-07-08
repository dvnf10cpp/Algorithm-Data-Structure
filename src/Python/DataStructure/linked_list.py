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
        return "<Node data: %s>" % str(self.data);

# Singly Linked List
class SinglyLinkedList : 
    def __init__(self) -> None:
        self.head = None;

    def isEmpty(self) -> bool :
        return self.head == None;

    def size(self) -> int :
        # runs in linear time
        # return number of nodes in sll
        current = self.head;
        count = 0;
        while (current != None) :
            count += 1;
            current = current.next;

        return count;

    def add_next(self, value : any) -> None : 
        # Add next reference to linked list
        new_node = Node(value);
        if (self.head == None) :
            self.head = new_node;
            return;

        current = self.head;
        while(current.next != None) :
            current = current.next;

        current.next = new_node;

    def append(self, value : any) -> None : 
        # Append new node at the beginning of the linked list
        new_node = Node(value);
        new_node.next = self.head;
        self.head = new_node;
    
    def search(self, key : any) -> Node :
        # Searching for the first node containing data that matches the parameter (key)
        current = self.head;
        while (current != None) :
            if (current.data == key) :
                return current;
            current = current.next;

        return None; # return None (null) if it doesnt exist

    def exist(self, key : any) -> bool :
        if (self.search(key) != None) :
            return True;
        return False;

    def __str__(self) -> None : 
        info = [];
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
        node_1 = Node(10);
        node_2 = Node("Me");
        print(node_1);
        print(node_2);

        node_1.next = node_2;
        print(node_1.next);

    def demo_sll() -> None : 
        sll = SinglyLinkedList();
        
        sll.add_next(5);
        sll.add_next(10);
        print("Size: ", sll.size());

        print(sll);
        sll.append(3);
        print(sll);
        print(sll.exist(10));

Demo.demo_node(); 
print("==================================")
Demo.demo_sll(); 