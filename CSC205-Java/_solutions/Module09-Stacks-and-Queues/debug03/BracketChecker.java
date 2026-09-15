// Checks whether the brackets ( ) [ ] { } in a string are balanced and properly nested.
public class BracketChecker {
    public static boolean isBalanced(String text) {
        CharStack stack = new CharStack(text.length());
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (c == '(' || c == '[' || c == '{') {
                stack.push(c);
            } else if (c == ')' || c == ']' || c == '}') {
                if (stack.isEmpty()) {
                    return false;
                }
                char open = stack.pop();
                if (!matches(open, c)) {
                    return false;
                }
            }
        }
        return stack.isEmpty();
    }

    private static boolean matches(char open, char close) {
        return (open == '(' && close == ')')
            || (open == '[' && close == ']')
            || (open == '{' && close == '}');
    }

    public static void main(String[] args) {
        String[] tests = {
            "(a + b) * [c]",
            "{[()]}",
            "[(])",
            "((a)",
            ")(",
            ""
        };
        for (String t : tests) {
            System.out.printf("%-16s %s%n", "\"" + t + "\"", isBalanced(t) ? "balanced" : "NOT balanced");
        }
    }
}
