package Java.LinkedList;

import java.util.LinkedList;

public class Main {
    public static void main(String[] args) {
        LinkedList<String> ll = new LinkedList<>();
        
        ll.addFirst("Satu");
        ll.addFirst("Dua");
        ll.addFirst("Tiga");

        for (String a : ll) {
            System.out.println(a);
        }
    }
}
