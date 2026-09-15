% sales_log.pl
% A running tally of items sold, kept as facts in the dynamic database.
% sell/1 records one sale, sales/2 reports the tally for one item,
% total_sold/1 adds every tally together, and reset_sales/0 clears the
% tallies for a new day.

:- dynamic sold/2.

sold(apples, 0).
sold(pears, 0).

sell(Item) :-
    retract(sold(Item, N)),
    N1 is N + 1,
    assert(sold(Item, N1)).

sales(Item, N) :-
    sold(Item, N).

total_sold(Total) :-
    bagof(N, sold(_, N), Ns),
    sum_list(Ns, Total).

reset_sales :-
    retract(sold(_, _)),
    assert(sold(apples, 0)),
    assert(sold(pears, 0)).
