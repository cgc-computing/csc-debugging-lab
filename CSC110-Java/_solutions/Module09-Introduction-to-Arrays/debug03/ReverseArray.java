// ReverseArray.java
// Reverses an array of integers in place (without creating a second
// array) by swapping elements from the two ends toward the middle.

public class ReverseArray {
    public static void main(String[] args) {
        int[] values = {3, 8, 12, 5, 21, 7};

        System.out.print("Original: ");
        printArray(values);

        reverse(values);

        System.out.print("Reversed: ");
        printArray(values);
    }

    // Swaps values[i] with its mirror element from the other end.
    public static void reverse(int[] arr) {
        for (int i = 0; i < arr.length / 2; i++) {
            int mirror = arr.length - 1 - i;
            int temp = arr[i];
            arr[i] = arr[mirror];
            arr[mirror] = temp;
        }
    }

    public static void printArray(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]);
            if (i < arr.length - 1) {
                System.out.print(", ");
            }
        }
        System.out.println();
    }
}
