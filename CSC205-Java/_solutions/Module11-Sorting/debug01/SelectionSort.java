// Selection sort: on each pass, find the smallest remaining value
// and move it to the front of the unsorted section.
public class SelectionSort {

    public static void sort(int[] a) {
        int n = a.length;
        for (int i = 0; i < n - 1; i++) {
            int minIndex = i;
            for (int j = i + 1; j < n; j++) {
                if (a[j] < a[minIndex]) {
                    minIndex = j;
                }
            }
            swap(a, i, minIndex);
        }
    }

    private static void swap(int[] a, int x, int y) {
        int tmp = a[x];
        a[x] = a[y];
        a[y] = tmp;
    }

    public static boolean isSorted(int[] a) {
        for (int i = 1; i < a.length; i++) {
            if (a[i - 1] > a[i]) {
                return false;
            }
        }
        return true;
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
        int[] data = {29, 10, 14, 37, 13, 5};
        System.out.println("Before: " + show(data));
        sort(data);
        System.out.println("After:  " + show(data));
        System.out.println("Sorted? " + isSorted(data));

        int[] small = {3, 1, 2};
        sort(small);
        System.out.println("Small:  " + show(small) + "  sorted? " + isSorted(small));
    }
}
