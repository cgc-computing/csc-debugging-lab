# Coldest Reading of the Day

**Course:** CSC101 &nbsp;|&nbsp; **Module 8:** Algorithm Design and the Software Lifecycle &nbsp;|&nbsp; **Activity:** debug01  
**Language:** Python 3

## Goal

A weather station records several temperature readings during the day. The program implements
this algorithm from the design document:

```
1. Ask for the number of readings, n.
2. Read the n temperatures one at a time.
3. Keep track of the coldest temperature seen so far and which reading it was
   (1 for the first reading, 2 for the second, and so on).
4. Report the coldest temperature and its position.
```

## Expected Behavior

```
How many readings? 5
Reading 1 (degrees F): 41
Reading 2 (degrees F): 38
Reading 3 (degrees F): 45
Reading 4 (degrees F): 36
Reading 5 (degrees F): 40

Coldest reading: 36.0 F (reading #4)
```

## How to Run

```bash
python3 coldest_reading.py
```

Type `5`, then `41`, `38`, `45`, `36`, `40`, pressing Enter after each.

## Your Task

Trace the program by hand against the algorithm above using the sample readings, then run it and
compare. This program contains one or more bugs. Fix them so the program matches the Expected
Behavior, and be ready to explain *why* the original version behaved the way it did. Do not rewrite
the program; the structure is fine.

## Think About

* Before the first reading is entered, what does "the coldest temperature seen so far" mean? What
  value, if any, makes sense for it?
* Trace the loop by hand: after each reading, write down `coldest` and `coldest_position`. At
  which reading does your trace first disagree with what the algorithm intends?
* Would the program give the right answer for the readings `-5, -12, -3`? Why is that different
  from the sample data?
