// Pushes a few values, peeks, then pops everything.
public class Main {
    public static void main(String[] args) {
        ArrayStack stack = new ArrayStack(8);
        stack.push(10);
        stack.push(20);
        stack.push(30);
        System.out.println("size after 3 pushes: " + stack.size());
        System.out.println("peek: " + stack.peek());

        while (!stack.isEmpty()) {
            System.out.println("pop:  " + stack.pop());
        }
        System.out.println("empty: " + stack.isEmpty());
    }
}
