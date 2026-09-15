# Solution: Course Rosters

**Course/Module/Activity:** CSC110 · Module 8 Designing Classes · debug01
**Bug type(s):** conceptual/design
**Bug count:** 1

## Observed Behavior

Both sections list all five students, and the total is doubled:

```
CSC110 Intro to Programming -- 5 student(s): Ada, Grace, Linus, Dennis, Barbara
CSC205 Data Structures -- 5 student(s): Ada, Grace, Linus, Dennis, Barbara

Total enrollment across both sections: 10
```

## The Bug(s)

`CourseTester.java`, in `main`: one `Roster` object is created and the same reference is passed to both `Course` constructors.

```java
Roster roster = new Roster();
Course intro = new Course("CSC110", "Intro to Programming", roster);
Course dataStructures = new Course("CSC205", "Data Structures", roster);
```

`Roster.java` and `Course.java` are correct.

## Why the Program Behaved Incorrectly

`roster` holds a *reference* to a single `Roster` object. Passing it to two constructors copies the reference, not the object, so both courses' `roster` fields point at the same object. Every `enroll` call — from either course — adds to that one shared roster. Printing either course prints the same roster, and the total counts it twice.

## The Concept This Illustrates

Reference semantics in aggregation. A field of object type holds a pointer to an object, and several objects can share one. When each container is supposed to own its own part, a separate `new` is required for each. Students tend to think of `roster` as "the roster data" rather than "the address of one roster object."

## The Correction

```java
// before
Roster roster = new Roster();
Course intro = new Course("CSC110", "Intro to Programming", roster);
Course dataStructures = new Course("CSC205", "Data Structures", roster);

// after
Course intro = new Course("CSC110", "Intro to Programming", new Roster());
Course dataStructures = new Course("CSC205", "Data Structures", new Roster());
```

(Or keep two named variables: `Roster introRoster = new Roster(); Roster dsRoster = new Roster();`.)

## Instructor Notes

- An alternative design fix is to have `Course`'s constructor create its own roster (`this.roster = new Roster();`) and drop the parameter. That is arguably a better design (composition); discuss when a class should build its own parts versus accept them.
- A wrong fix is to make `Course` copy the roster's *fields* out of the parameter — it works here but is fragile; ask what happens if `Roster` gains more fields.
- Have students draw the object diagram before and after. The "two arrows to one box" picture is the whole lesson.
- Connect back to Module 6 pass-by-value: the *reference* is passed by value, which is exactly why both courses end up with the same object.
