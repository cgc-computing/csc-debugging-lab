// Recursive string utilities: count occurrences of a character and reverse a string.
public class StringRecursion {
    public static int countChar(String s, char c) {
        if (s.isEmpty()) {
            return 0;
        }
        int count = 0;
        if (s.charAt(0) == c) {
            count++;
        }
        countChar(s.substring(1), c);
        return count;
    }

    public static String reverse(String s) {
        if (s.length() <= 1) {
            return s;
        }
        return reverse(s.substring(1)) + s.charAt(0);
    }

    public static void main(String[] args) {
        System.out.println("s in mississippi: " + countChar("mississippi", 's'));
        System.out.println("a in banana:      " + countChar("banana", 'a'));
        System.out.println("a in aardvark:    " + countChar("aardvark", 'a'));
        System.out.println("z in hello:       " + countChar("hello", 'z'));
        System.out.println("reverse(recursion) = " + reverse("recursion"));
    }
}
