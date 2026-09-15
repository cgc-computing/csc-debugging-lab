// A singly linked list of integers supporting removal by value.
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

    // Removes the first node holding value. Returns true if something was removed.
    public boolean remove(int value) {
        if (head == null) {
            return false;
        }
        if (head.value == value) {
            head = head.next;
            if (head == null) {
                tail = null;
            }
            size--;
            return true;
        }
        Node prev = head;
        Node cur = head.next;
        while (cur != null) {
            if (cur.value == value) {
                prev.next = cur.next;
                if (cur == tail) {
                    tail = prev;
                }
                size--;
                return true;
            }
            prev = cur;
            cur = cur.next;
        }
        return false;
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
        return sb.length() == 0 ? "(empty)" : sb.toString();
    }
}
