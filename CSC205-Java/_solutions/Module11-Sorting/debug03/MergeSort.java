// Top-down merge sort. The array is split in half, each half is sorted
// recursively, and the two sorted halves are merged through a scratch array.
public class MergeSort {

    public static void sort(int[] a) {
        int[] temp = new int[a.length];
        sort(a, temp, 0, a.length - 1);
    }

    private static void sort(int[] a, int[] temp, int lo, int hi) {
        if (lo >= hi) {
            return;
        }
        int mid = (lo + hi) / 2;
        sort(a, temp, lo, mid);
        sort(a, temp, mid + 1, hi);
        merge(a, temp, lo, mid, hi);
    }

    // Merges the sorted ranges a[lo..mid] and a[mid+1..hi].
    private static void merge(int[] a, int[] temp, int lo, int mid, int hi) {
        int i = lo;        // next unused element of the left half
        int j = mid + 1;   // next unused element of the right half
        int k = lo;        // next free slot in temp

        while (i <= mid && j <= hi) {
            if (a[i] <= a[j]) {
                temp[k++] = a[i++];
            } else {
                temp[k++] = a[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = a[i++];
        }
        while (j <= hi) {
            temp[k++] = a[j++];
        }

        for (int m = lo; m <= hi; m++) {
            a[m] = temp[m];
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
        int[] data = {38, 27, 43, 3, 9, 82, 10};
        System.out.println("Before: " + show(data));
        sort(data);
        System.out.println("After:  " + show(data));

        int[] pair = {2, 1};
        sort(pair);
        System.out.println("Pair:   " + show(pair));

        int[] halves = {5, 6, 7, 1, 2, 3};
        sort(halves);
        System.out.println("Halves: " + show(halves));
    }
}
