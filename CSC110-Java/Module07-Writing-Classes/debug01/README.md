# Rectangle Class

**Course:** CSC110 &nbsp;|&nbsp; **Module 7:** Writing Classes &nbsp;|&nbsp; **Activity:** debug01
**Language:** Java 17+

## Goal

`Rectangle` represents a rectangle with a width and a height. It has a constructor, getters and setters, and methods for area and perimeter. `RectangleTester` creates a poster (18 x 24 inches) and a photo (4 x 6 inches), prints their measurements, then widens the photo to 5 inches and prints again.

## Expected Behavior

```
Poster: 18.0 x 24.0
  area = 432.0, perimeter = 84.0
Photo:  4.0 x 6.0
  area = 24.0, perimeter = 20.0
After widening the photo to 5 inches:
  area = 30.0, perimeter = 22.0
```

## How to Run

```bash
javac *.java
java RectangleTester
```

The program takes no input.

## Your Task

Run the program and compare the output with the Expected Behavior. This program contains one or more bugs. Fix them so the program matches the Expected Behavior, and be ready to explain *why* the original version behaved the way it did. The tester is correct; look at the class.

## Think About

- Right after `new Rectangle(18.0, 24.0)` finishes, what values do you expect the object's two fields to hold?
- Can a parameter and a field share the same name? If they do, which one does a bare name refer to, and how would you refer to the other one?
- Why does the perimeter change after `setWidth(5.0)` while the area stays at zero? What does that tell you about the two fields?
