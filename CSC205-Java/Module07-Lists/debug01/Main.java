// Builds a list by appending values and prints it.
public class Main {
    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(40);
        System.out.println("List: " + list);
        System.out.println("Size: " + list.size());

        list.addFirst(5);
        list.addLast(50);
        System.out.println("List: " + list);
        System.out.println("Size: " + list.size());
    }
}
