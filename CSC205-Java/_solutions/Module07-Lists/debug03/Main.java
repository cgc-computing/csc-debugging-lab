// Removes values from a list and reports the result of each removal.
public class Main {
    public static void main(String[] args) {
        SinglyLinkedList list = new SinglyLinkedList();
        list.addLast(10);
        list.addLast(20);
        list.addLast(30);
        list.addLast(40);
        System.out.println("Start:      " + list + "   size " + list.size());

        int[] toRemove = {30, 10, 99, 40};
        for (int v : toRemove) {
            boolean removed = list.remove(v);
            System.out.println("remove(" + v + "): " + (removed ? "removed" : "not found")
                    + "   -> " + list + "   size " + list.size());
        }

        list.addLast(50);
        System.out.println("addLast(50): " + list + "   size " + list.size());
    }
}
