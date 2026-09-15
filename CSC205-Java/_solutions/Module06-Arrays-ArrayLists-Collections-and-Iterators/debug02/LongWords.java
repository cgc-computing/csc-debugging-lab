import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

// Prints every word in a list that is longer than a given length, using an Iterator.
public class LongWords {
    public static void printLongerThan(List<String> words, int minLength) {
        Iterator<String> it = words.iterator();
        while (it.hasNext()) {
            String word = it.next();
            if (word.length() > minLength) {
                System.out.println(word);
            }
        }
    }

    public static void main(String[] args) {
        List<String> words = new ArrayList<>();
        String[] data = {"tree", "binary", "node", "stack", "queue", "graph", "heap", "recursion"};
        for (String w : data) {
            words.add(w);
        }

        System.out.println("Words longer than 4 letters:");
        printLongerThan(words, 4);
        System.out.println("Done.");
    }
}
