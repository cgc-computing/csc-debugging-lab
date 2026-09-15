; curried-adders.scm
; A curried adder: (add a) returns a procedure that adds a to its
; argument. The other procedures use it to build adders and to apply a
; bonus to a list of scores.

(define (add a)
  (lambda (b) (+ a b)))

(define add5 (add 5))

(define (add-to-all n lst)
  (map (add n) lst))

(define (total-with-bonus bonus scores)
  (apply + (map (lambda (s) ((add bonus) s)) scores)))
