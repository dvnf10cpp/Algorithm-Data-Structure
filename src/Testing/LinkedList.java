package Testing;

public class LinkedList<Type>{
    Node<Type> head;
    LinkedList() { this.head = null; }
    LinkedList(Node<Type> data) { this.head = data; }

    void append(Type data) {
        // add to the tail
        if (head == null) {
            head = new Node<Type>(data);
            return;
        }
        Node<Type> current = head;
        while (current.next != null ) {
            current = current.next;
        }
        current.next = new Node<>(data);
    }

    void prepend(Type data) {
        // add to the head
        Node<Type> current = new Node<Type>(data);
        current.next = head;
        this.head = current;
    }

    void insert(int index, Type data) {
        if (index < 0 || index > this.size()) {
            throw new IndexOutOfBoundsException();
        }
        if(index == 0) {    
            prepend(data);
            return;
        }
        Node<Type> node = new Node<Type>(data);
        Node<Type> current = head;
        while (index > 1) {
            current = current.next;
        }
        node.next = current.next;
        current.next = node;
    }

    void set(int index, Type data) {
        if (index < 0 || index > this.size()) {
            throw new IndexOutOfBoundsException();
        }
        Node<Type> current = head;
        while (index-- > 0) {
            current = current.next;
        }
        current.data =  data;
    }

    void set(int index, Node<Type> node) {
        if (index < 0 || index > this.size()) {
            throw new IndexOutOfBoundsException();
        }
        Node<Type> current = head;
        while (index-- > 0) {
            current = current.next;
        }
        node.next = current.next.next;
        current.next = node;
    }

    void remove(int index) {
        if (index < 0 || index > this.size()) {
            throw new IndexOutOfBoundsException();
        }
        if (index == 0) {
            this.head = head.next;
            return;
        }
        Node<Type> current = head;
        while(index-- > 1) {
            current = current.next;
        }
        current.next = current.next.next;
    }

    int lastOfIndex(Type data) {
        Node<Type> current = head;
        int counter = 0, max = -1;
        while(current != null) {
            if (current.data.equals(data)) {
                max = counter;
            }
            current = current.next;
            counter++;
        }
        return max;
    }

    boolean contain(Type value) {
        Node<Type> current = head;
        while(current != null) {
            if (current.data.equals(value)) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    boolean contain(Node<Type> node) {
        Node<Type> current = head;
        while(current != null) {
            if (current.data.equals(node.data)) {
                return true;
            }
            current = current.next;
        }
        return false;
    }

    void clear() {
        this.head = null;
    }

    boolean isEmpty() {
        return head == null;
    }

    int size() {
        int counter = 0;
        Node<Type> current = head;
        while (current != null) {
            counter++;
            current = current.next;
        }
        return counter;
    }

    Node<Type> get(int index) {
        if (index < 0 || index > this.size()) {
            throw new IndexOutOfBoundsException();
        }

        Node<Type> current = head;
        while (index-- > 0) {
            current = current.next;
        }
        return current;
    }

    public String toString() {
        String res = "";
        Node<Type> current = head;
        while (current != null) {
            res += "[" + current.data + "] >> ";
            current = current.next; 
        }
        return res;
    }
}

