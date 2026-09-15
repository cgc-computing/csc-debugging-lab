% enrollment.pl
% Students and course enrollments, with rules to find students who are
% not yet enrolled in anything and pairs of students taking a course
% together.

student(ana).
student(ben).
student(cy).
student(dana).

enrolled(ana, csc240).
enrolled(ben, csc240).
enrolled(cy, csc205).

unenrolled(S) :-
    \+ enrolled(S, _),
    student(S).

takes_with(S1, S2, Course) :-
    enrolled(S1, Course),
    enrolled(S2, Course),
    S1 \= S2.
