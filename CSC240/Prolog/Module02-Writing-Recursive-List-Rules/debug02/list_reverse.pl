% list_reverse.pl
% Reversing a list with plain recursion. my_reverse(List, Reversed) is
% true when Reversed holds the elements of List in the opposite order.
% my_append is a hand-written version of append/3, kept here as a helper.

my_append([], L, L).
my_append([H|T], L, [H|R]) :-
    my_append(T, L, R).

my_reverse([], []).
my_reverse([H|T], R) :-
    my_reverse(T, RT),
    R = [H|RT].
