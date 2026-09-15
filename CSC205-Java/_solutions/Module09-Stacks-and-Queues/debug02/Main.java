// Simulates a print queue with a small circular buffer.
public class Main {
    public static void main(String[] args) {
        CircularQueue jobs = new CircularQueue(5);
        for (int job = 1; job <= 5; job++) {
            jobs.enqueue(job);
        }
        System.out.println("queued:   " + jobs);

        System.out.println("finished: " + jobs.dequeue());
        System.out.println("finished: " + jobs.dequeue());
        System.out.println("queued:   " + jobs);

        jobs.enqueue(6);
        jobs.enqueue(7);
        System.out.println("queued:   " + jobs);

        while (!jobs.isEmpty()) {
            System.out.println("finished: " + jobs.dequeue());
        }
    }
}
