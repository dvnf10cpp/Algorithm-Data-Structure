package Java;

import Java.my.datastructure.LinkedList;

public class DemoSLL {
    public static void main(String[] args) {
        LinkedList<String> ll = new LinkedList<>();
        
        ll.addFirst("Satu");
        ll.addFirst("Dua");
        ll.addFirst("Tiga");

        for (String a : ll) {
            System.out.println(a);
        }

        ll.remove(0);

        for (String a : ll) {
            System.out.println(a);
        }
    }
}
