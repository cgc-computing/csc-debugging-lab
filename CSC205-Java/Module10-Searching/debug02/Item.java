// One product in a small hardware-store inventory.
public class Item {
    private final String name;
    private final int sku;

    public Item(String name, int sku) {
        this.name = name;
        this.sku = sku;
    }

    public String getName() {
        return name;
    }

    public int getSku() {
        return sku;
    }

    @Override
    public boolean equals(Object other) {
        if (this == other) {
            return true;
        }
        if (!(other instanceof Item)) {
            return false;
        }
        Item o = (Item) other;
        return sku == o.sku && name.equals(o.name);
    }

    @Override
    public int hashCode() {
        return 31 * name.hashCode() + sku;
    }

    @Override
    public String toString() {
        return name + " (#" + sku + ")";
    }
}
