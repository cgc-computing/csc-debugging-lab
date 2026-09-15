// RainfallTable.java
// Stores three years of quarterly rainfall totals (inches) in a 2-D
// array and prints each year's total plus the grand total.

public class RainfallTable {
    public static void main(String[] args) {
        // rows = years, columns = quarters Q1..Q4
        double[][] rainfall = {
            {3.2, 4.1, 2.8, 5.0},
            {2.9, 3.7, 3.3, 4.6},
            {4.0, 3.9, 2.5, 5.4}
        };
        int[] years = {2022, 2023, 2024};

        double grandTotal = 0.0;

        System.out.println("Year    Q1    Q2    Q3    Q4   Total");
        for (int row = 0; row < rainfall.length; row++) {
            double yearTotal = 0.0;
            System.out.print(years[row] + " ");
            for (int col = 0; col < rainfall[row].length; col++) {
                System.out.printf("%5.1f ", rainfall[row][col]);
                yearTotal += rainfall[row][col];
            }
            System.out.printf("   %5.1f%n", yearTotal);
            grandTotal += yearTotal;
        }

        System.out.println();
        System.out.printf("Three-year total: %.1f inches%n", grandTotal);
    }
}
