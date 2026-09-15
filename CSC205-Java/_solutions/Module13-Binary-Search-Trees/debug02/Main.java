// Builds a set of student ID numbers and answers membership questions.
public class Main {
    public static void main(String[] args) {
        BST ids = new BST();
        int[] keys = {50, 30, 70, 20, 40, 60, 80, 30, 70};
        for (int k : keys) {
            ids.insert(k);
        }
        System.out.println("in-order: " + ids.inOrder());
        System.out.println("size:     " + ids.size());

        int[] queries = {40, 65, 80, 20, 50, 10};
        for (int q : queries) {
            System.out.println("contains(" + q + "): " + ids.contains(q));
        }
    }
}
