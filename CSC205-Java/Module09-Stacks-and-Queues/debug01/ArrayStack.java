// A stack of integers stored in a fixed-size array.
// top is the number of items currently on the stack.
public class ArrayStack {
    private int[] data;
    private int top;

    public ArrayStack(int capacity) {
        data = new int[capacity];
        top = 0;
    }

    public boolean isEmpty() {
        return top == 0;
    }

    public int size() {
        return top;
    }

    public void push(int value) {
        if (top == data.length) {
            throw new RuntimeException("stack is full");
        }
        data[top] = value;
        top++;
    }

    public int pop() {
        if (isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        int value = data[top];
        top--;
        return value;
    }

    public int peek() {
        if (isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        return data[top];
    }
}
