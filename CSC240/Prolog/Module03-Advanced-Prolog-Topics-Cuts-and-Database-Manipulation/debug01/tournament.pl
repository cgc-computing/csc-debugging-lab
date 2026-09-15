% tournament.pl
% Scoring helpers for a small tournament. my_max/3 picks the larger of
% two scores, loses_to/2 says one score loses to another, and
% best_score/2 finds the highest score in a list.

my_max(X, Y, X) :-
    X >= Y,
    !.
my_max(_, Y, Y).

loses_to(Score, Other) :-
    my_max(Score, Other, Other),
    Score =\= Other.

best_score([S], S).
best_score([H|T], Best) :-
    best_score(T, BestOfRest),
    my_max(H, BestOfRest, Best).
