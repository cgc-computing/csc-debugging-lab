% list_basics.pl
% Two recursive list predicates written from scratch:
% my_length(List, N) is true when N is the number of elements in List,
% and my_last(List, X) is true when X is the final element of List.

my_length([], 0).
my_length([_|T], N) :-
    my_length(T, N),
    N is N + 1.

my_last([X], X).
my_last([_|T], X) :-
    my_last(T, X).
