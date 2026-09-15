% campus_store.pl
% Prices for a small campus store and rules for working out what an
% order costs, whether it fits a budget, and which item is cheaper.

price(pen, 2).
price(notebook, 5).
price(backpack, 40).

cost(Item, Qty, Total) :-
    price(Item, Price),
    Total = Price * Qty.

affordable(Item, Qty, Budget) :-
    cost(Item, Qty, Total),
    Total =< Budget.

cheaper(Item1, Item2) :-
    price(Item1, P1),
    price(Item2, P2),
    P1 < P2.
