% ancestry.pl
% A family tree with a recursive ancestor relation. ancestor(A, D) is
% true when A is a parent, grandparent, great-grandparent, ... of D.
% descendant/2 is the same relation read the other way round.

parent(tom, bob).
parent(tom, liz).
parent(bob, ann).
parent(bob, pat).
parent(pat, jim).

ancestor(A, D) :-
    parent(A, D).
ancestor(A, D) :-
    parent(A, X),
    ancestor(X, D).

descendant(D, A) :-
    ancestor(A, D).
