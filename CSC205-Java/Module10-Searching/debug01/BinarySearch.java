// Binary search over a sorted array of exam scores.
// Reports the index where each target lives, or -1 if it is absent.
public class BinarySearch {

    // Returns the index of target in the sorted array a, or -1 if not present.
    public static int binarySearch(int[] a, int target) {
        int low = 0;
        int high = a.length - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (a[mid] == target) {
                return mid;
            } else if (a[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return -1;
    }

    // Plain linear search, used to double-check the results.
    public static int linearSearch(int[] a, int target) {
        for (int i = 0; i < a.length; i++) {
            if (a[i] == target) {
                return i;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        int[] scores = {3, 8, 15, 21, 27, 34, 42, 50};
        int[] targets = {21, 3, 50, 40};

        System.out.print("Scores:");
        for (int s : scores) {
            System.out.print(" " + s);
        }
        System.out.println();

        for (int t : targets) {
            int index = binarySearch(scores, t);
            int check = linearSearch(scores, t);
            String where = (index < 0) ? "not found" : "index " + index;
            System.out.println("search " + t + ": " + where
                    + "   (linear search says " + check + ")");
        }
    }
}
