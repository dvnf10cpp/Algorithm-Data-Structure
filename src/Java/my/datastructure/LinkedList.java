package Java.my.datastructure;

import java.util.Iterator;

public class LinkedList<T> implements Iterable<T> {
    Node head;
    Node tail;
    public boolean isEmpty(){
        return head==null;
    }

    public void addLast(T newData){   
        if(isEmpty()) {
            head = new Node(newData);
            tail=head;
            return;
        }
        Node node = new Node(newData);
        tail.next = node;
        tail = node;
        tail.next = null;
    }

    public void addFirst(T newData){
        if(isEmpty()) {
            head = new Node(newData);
            tail=head;
            return;
        }
        Node node = new Node(newData);
        node.next= head;
        head = node;
    }

    public void insertAt(int index, T newData) {
        if(index == 0) {
            addFirst(newData);
            return;
        }

        Node node = new Node(newData);
        Node curr = head;
        while(--index > 0) {
            curr = curr.next;
        }
        node.next = curr.next;
        curr.next = node;
    }

    public boolean contains(T data) {
        Node curr = head;
        while(curr != null) {
            if(curr.data.equals(data)) {
                return true;
            }
            curr = curr.next;
        }
        return false;
    }

    public boolean remove(int index) {
        if(index < 0 || index >= size()) {
            throw new IndexOutOfBoundsException(index);
        }

        Node curr = head;
        if(index == 0) {
            head = head.next;
            return true;
        }
        while(--index > 0) {
            curr = curr.next;
        }
        curr.next = curr.next.next;
        return true;
    }
    
    public T getFirst() {
        return head.data;
    }
    
    public T getLast() {
        return tail.data;
    }

    public Iterator<T> iterator() {
        return new SLLIterator(this);
    }

    public String toString(){
        Node curr = head;
        String res = "";
        while(curr != null) {
            res += curr.data;
            curr = curr.next;
            if(curr!=null) res += "-";
        }
        return res;
    }
    
    int size() {
        Node curr = head;
        int counter=0;
        while(curr!=null){
            counter++;
            curr=curr.next;
        }
        return counter;
    }

    class Node{
        T data;
        Node next;
        
        Node(T data){
            this.data = data;
        }   
    }

    class SLLIterator implements Iterator<T> {
        Node current;

        public SLLIterator(LinkedList<T> sll) {
            current = sll.head;
        }

        public boolean hasNext() {
            return current != null;
        }

        public T next() {
            T data = current.data;
            current = current.next;
            return data;
        }
    }
}



