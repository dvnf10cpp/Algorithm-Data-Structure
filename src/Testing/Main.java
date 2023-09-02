package Testing;

public class Main {
    public static void main(String[] args) {
        testingOne();
    }


    static void testingOne() {
        LinkedList<Integer> sll = new LinkedList<>();

        sll.append(5);
        sll.append(10);
        sll.prepend(2);
        // 4 3 5 10
        System.out.println(sll);
        System.out.println(sll.size());

        System.out.println(sll.get(0));
        sll.insert(1,3);
        System.out.println(sll);
        sll.set(0, 4);
        sll.set(1, 5);
        sll.set(1, new Node<>(6));
        System.out.println(sll);
        sll.remove(3);
        System.out.println(sll);
        sll.prepend(5);
        sll.append(5);
        System.out.println(sll);
        System.out.println(sll.lastOfIndex(5));
    }
}