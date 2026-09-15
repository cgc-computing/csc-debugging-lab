// Thrown when a score is outside the 0-100 range.
public class InvalidScoreException extends Exception {
    public InvalidScoreException(String message) {
        super(message);
    }
}
