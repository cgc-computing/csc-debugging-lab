# Solution: Honor Roll

**Course/Module/Activity:** CSC110 · Module 10 More About Arrays · debug02
**Bug type(s):** runtime
**Bug count:** 1

## Observed Behavior

The program crashes on the first setter call:

```
Exception in thread "main" java.lang.NullPointerException: Cannot invoke "Student.setName(String)" because "<local1>[<local4>]" is null
	at HonorRoll.main(HonorRoll.java:13)
```

## The Bug(s)

`HonorRoll.java`, in `main`: the array is created but no `Student` objects are ever constructed.

```java
Student[] roster = new Student[4];
...
for (int i = 0; i < roster.length; i++) {
    roster[i].setName(names[i]);
    roster[i].setGpa(gpas[i]);
}
```

## Why the Program Behaved Incorrectly

`new Student[4]` allocates an array of four *references*, each initialized to `null`. It does not create any `Student` objects. The first iteration calls `roster[0].setName(...)` on a `null` reference, which throws `NullPointerException`. The JVM's message even says which expression was null: an element of a local array.

## The Concept This Illustrates

An array of objects is an array of references. Creating the array and creating its elements are two separate steps, and each element needs its own `new`. Students carry over the intuition from `int[]`, where `new int[4]` really does produce four usable zeros.

## The Correction

```java
// before
for (int i = 0; i < roster.length; i++) {
    roster[i].setName(names[i]);
    roster[i].setGpa(gpas[i]);
}

// after
for (int i = 0; i < roster.length; i++) {
    roster[i] = new Student();
    roster[i].setName(names[i]);
    roster[i].setGpa(gpas[i]);
}
```

## Instructor Notes

- Students who have only seen primitive arrays are often genuinely surprised that `new Student[4]` "doesn't make students." Draw the array with four `null` boxes.
- Some will "fix" it by adding `if (roster[i] != null)` around the setter calls — the crash disappears and so does all the output. Ask what the program is now doing.
- A design follow-up: give `Student` a two-argument constructor and write `roster[i] = new Student(names[i], gpas[i]);`. Compare the two styles.
- Connect to `ArrayList`: `new ArrayList<Student>()` starts *empty* (size 0) rather than with `null` slots; ask how the same mistake would look there (`get(0)` throws `IndexOutOfBoundsException`).
