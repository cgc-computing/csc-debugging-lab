// A FIFO queue of integers stored in a circular (ring) array.
public class CircularQueue {
    private int[] data;
    private int front;   // index of the oldest item
    private int rear;    // index where the next item will be stored
    private int size;

    public CircularQueue(int capacity) {
        data = new int[capacity];
        front = 0;
        rear = 0;
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public boolean isFull() {
        return size == data.length;
    }

    public void enqueue(int value) {
        if (isFull()) {
            throw new RuntimeException("queue is full");
        }
        data[rear] = value;
        rear = rear + 1;
        size++;
    }

    public int dequeue() {
        if (isEmpty()) {
            throw new RuntimeException("queue is empty");
        }
        int value = data[front];
        front = (front + 1) % data.length;
        size--;
        return value;
    }

    public String toString() {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < size; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(data[(front + i) % data.length]);
        }
        return sb.append("]").toString();
    }
}
