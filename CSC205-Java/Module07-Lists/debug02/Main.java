// Inserts values at chosen positions and prints the list after each insertion.
public class Main {
    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(40);
        System.out.println("Start:            " + list);

        list.insertAt(0, 5);
        System.out.println("insertAt(0, 5):   " + list);

        list.insertAt(2, 15);
        System.out.println("insertAt(2, 15):  " + list);

        list.insertAt(6, 45);
        System.out.println("insertAt(6, 45):  " + list);
        System.out.println("Size: " + list.size());
    }
}
