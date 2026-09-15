import java.util.ArrayList;

// Removes every even number from a list of integers.
public class RemoveEvens {
    public static void removeEvens(ArrayList<Integer> values) {
        for (int i = 0; i < values.size(); i++) {
            if (values.get(i) % 2 == 0) {
                values.remove(i);
                i--;
            }
        }
    }

    public static void main(String[] args) {
        ArrayList<Integer> values = new ArrayList<>();
        int[] data = {3, 8, 6, 10, 7, 12, 14, 5, 2};
        for (int d : data) {
            values.add(d);
        }

        System.out.println("Before: " + values);
        removeEvens(values);
        System.out.println("After:  " + values);
    }
}
