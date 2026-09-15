// A simple array-based stack of characters.
public class CharStack {
    private char[] data;
    private int top;

    public CharStack(int capacity) {
        data = new char[capacity];
        top = 0;
    }

    public boolean isEmpty() {
        return top == 0;
    }

    public void push(char c) {
        if (top == data.length) {
            throw new RuntimeException("stack is full");
        }
        data[top++] = c;
    }

    public char pop() {
        if (isEmpty()) {
            throw new RuntimeException("stack is empty");
        }
        return data[--top];
    }
}
