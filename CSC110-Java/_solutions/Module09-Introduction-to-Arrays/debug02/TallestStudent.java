// TallestStudent.java
// Given parallel arrays of student names and heights (in inches), finds
// the tallest student and prints the name and height.

public class TallestStudent {
    public static void main(String[] args) {
        String[] names = {"Jordan", "Ines", "Malik", "Sofia", "Chen"};
        int[] heights = {66, 71, 69, 74, 68};

        int tallestIndex = 0;
        int tallestHeight = heights[0];

        for (int i = 1; i < heights.length; i++) {
            if (heights[i] > tallestHeight) {
                tallestHeight = heights[i];
                tallestIndex = i;
            }
        }

        System.out.println("Class heights:");
        for (int i = 0; i < names.length; i++) {
            System.out.println("  " + names[i] + ": " + heights[i] + " in");
        }

        System.out.println();
        System.out.println("Tallest student: " + names[tallestIndex]
                           + " at " + heights[tallestIndex] + " inches");
    }
}
