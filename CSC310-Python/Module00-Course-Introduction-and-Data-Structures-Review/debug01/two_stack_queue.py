"""A FIFO queue built from two LIFO stacks.

Elements are pushed onto an inbox stack.  When a dequeue is requested,
elements are moved to an outbox stack so that the oldest element is on
top.  Each element is moved at most once, so the amortized cost of every
operation is O(1).
"""


class TwoStackQueue:
    def __init__(self):
        self._inbox = []
        self._outbox = []

    def __len__(self):
        return len(self._inbox) + len(self._outbox)

    def is_empty(self):
        return len(self) == 0

    def enqueue(self, item):
        self._inbox.append(item)

    def _shift(self):
        # Move everything from the inbox to the outbox, reversing order.
        while self._inbox:
            self._outbox.append(self._inbox.pop())

    def dequeue(self):
        if self.is_empty():
            raise IndexError("dequeue from empty queue")
        self._shift()
        return self._outbox.pop()

    def peek(self):
        if self.is_empty():
            raise IndexError("peek at empty queue")
        self._shift()
        return self._outbox[-1]


def main():
    # Simulate a print server: jobs arrive in bursts and are printed in
    # arrival order.
    q = TwoStackQueue()
    served = []

    for job in ["report.pdf", "photo.png", "notes.txt"]:
        q.enqueue(job)
    served.append(q.dequeue())

    for job in ["slides.pptx", "invoice.pdf"]:
        q.enqueue(job)
    served.append(q.dequeue())
    served.append(q.dequeue())

    q.enqueue("resume.docx")
    while not q.is_empty():
        served.append(q.dequeue())

    print("Jobs printed, in order:")
    for i, job in enumerate(served, 1):
        print(f"  {i}. {job}")

    # A second check with integers, comparing against a plain list.
    q2 = TwoStackQueue()
    expected = []
    out = []
    for round_no in range(1, 5):
        for k in range(round_no):
            q2.enqueue(round_no * 10 + k)
            expected.append(round_no * 10 + k)
        out.append(q2.dequeue())
    while not q2.is_empty():
        out.append(q2.dequeue())
    print("Integer test matches FIFO order:", out == expected)
    print("Dequeued:", out)


if __name__ == "__main__":
    main()
