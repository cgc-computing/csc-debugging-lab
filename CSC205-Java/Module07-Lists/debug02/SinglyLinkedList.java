// A singly linked list of integers supporting insertion at any position.
public class SinglyLinkedList {
    private static class Node {
        int value;
        Node next;

        Node(int value) {
            this.value = value;
        }
    }

    private Node head;
    private Node tail;
    private int size;

    public void addFirst(int value) {
        Node n = new Node(value);
        n.next = head;
        head = n;
        if (tail == null) {
            tail = n;
        }
        size++;
    }

    public void addLast(int value) {
        Node n = new Node(value);
        if (head == null) {
            head = n;
        } else {
            tail.next = n;
        }
        tail = n;
        size++;
    }

    // Inserts value so that it ends up at position index (0 = front, size = end).
    public void insertAt(int index, int value) {
        if (index < 0 || index > size) {
            throw new IndexOutOfBoundsException("index " + index + ", size " + size);
        }
        if (index == 0) {
            addFirst(value);
            return;
        }
        Node cur = head;
        for (int i = 0; i < index; i++) {
            cur = cur.next;
        }
        Node n = new Node(value);
        n.next = cur.next;
        cur.next = n;
        if (n.next == null) {
            tail = n;
        }
        size++;
    }

    public int size() {
        return size;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder();
        for (Node cur = head; cur != null; cur = cur.next) {
            if (sb.length() > 0) {
                sb.append(" -> ");
            }
            sb.append(cur.value);
        }
        return sb.toString();
    }
}
