package Testing;

// C Variant, Limited in member funciton
public class ListNode<Type> {
    Type data;
    ListNode<Type> next;

    ListNode(){
        next = null;
    }

    ListNode(Type data) {
        this();
        this.data = data;
    }

    ListNode(Type data, ListNode<Type> next) {
        this(data);
        this.next = next;
    }

    void append(Type data) {
        // add to the tail
        if (next == null) {
            next = new ListNode<>(data);
            return;
        }
        ListNode<Type> curr = next;
        while(curr.next != null) {
            curr = curr.next;
        }
        curr.next = new ListNode<>(data);
    }

    int size() {
        int counter = 0;
        ListNode<Type> current = this;
        while(current != null) {
            current = current.next;
            counter++;
        }
        return counter;
    }

    public String toString() {
        String str = "";
        ListNode<Type> current = this;
        while(current != null) {
            str += "[" + current.data + "] >> ";
            current = current.next;
        }
        return str;
    }
}
