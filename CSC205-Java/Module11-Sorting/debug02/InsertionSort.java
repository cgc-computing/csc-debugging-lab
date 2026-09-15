// Insertion sort on a list of daily temperatures.
// Each new value is slid left until it sits after everything smaller.
public class InsertionSort {

    public static void sort(int[] a) {
        for (int i = 1; i < a.length; i++) {
            int key = a[i];
            int j = i - 1;
            while (a[j] > key && j >= 0) {
                a[j + 1] = a[j];
                j--;
            }
            a[j + 1] = key;
        }
    }

    private static String show(int[] a) {
        StringBuilder sb = new StringBuilder("[");
        for (int i = 0; i < a.length; i++) {
            if (i > 0) {
                sb.append(", ");
            }
            sb.append(a[i]);
        }
        return sb.append("]").toString();
    }

    public static void main(String[] args) {
        int[] highs = {72, 65, 80, 71, 68};
        System.out.println("Before: " + show(highs));
        sort(highs);
        System.out.println("After:  " + show(highs));

        int[] lows = {58, 61, 49, 55, 44, 60};
        System.out.println("Before: " + show(lows));
        sort(lows);
        System.out.println("After:  " + show(lows));
    }
}
