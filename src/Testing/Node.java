package Testing;

public class Node<Type> {
    Type data;
    Node<Type> next;

    Node() { next = null; }

    Node(Type data) { this(); this.data = data; }

    Node(Type data, Node<Type> next) { this.data = data; this.next = next; }

    public String toString() {
        return data.toString();
    }
}
