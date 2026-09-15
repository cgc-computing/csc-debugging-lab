// Linear search through an unsorted inventory of Item objects.
public class ItemSearch {

    // Returns the index of the first item equal to target, or -1.
    public static int indexOf(Item[] items, Item target) {
        for (int i = 0; i < items.length; i++) {
            if (items[i].equals(target)) {
                return i;
            }
        }
        return -1;
    }

    // Returns how many items in the array are equal to target.
    public static int count(Item[] items, Item target) {
        int n = 0;
        for (Item it : items) {
            if (it.equals(target)) {
                n++;
            }
        }
        return n;
    }

    public static void main(String[] args) {
        Item[] shelf = {
            new Item("hammer", 1001),
            new Item("wrench", 1002),
            new Item("pliers", 1003),
            new Item("wrench", 1002),
            new Item("saw", 1004)
        };

        // Search using the very same object that sits on the shelf.
        Item sameObject = shelf[2];
        System.out.println("indexOf " + sameObject + ": " + indexOf(shelf, sameObject));

        // Search using a fresh description of an item that is on the shelf.
        Item wrench = new Item("wrench", 1002);
        System.out.println("indexOf " + wrench + ": " + indexOf(shelf, wrench));
        System.out.println("count   " + wrench + ": " + count(shelf, wrench));

        // Search for something that is not stocked at all.
        Item drill = new Item("drill", 2001);
        System.out.println("indexOf " + drill + ": " + indexOf(shelf, drill));
    }
}
