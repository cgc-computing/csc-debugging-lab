% family_rules.pl
% A family tree with rules built on top of parent/2 facts:
% father, mother, grandparent, sibling, and sister.

parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).

male(tom).
male(bob).
male(jim).

female(liz).
female(ann).
female(pat).

father(X, Y) :-
    parent(X, Y),
    male(X).

mother(X, Y) :-
    parent(X, Y),
    female(X).

grandparent(X, Z) :-
    parent(X, Y),
    parent(Y, Z).

sibling(X, Y) :-
    parent(P, X),
    parent(P, Y),
    X \= Y.

sister(X, Y) :-
    sibling(X, Y),
    female(X).
