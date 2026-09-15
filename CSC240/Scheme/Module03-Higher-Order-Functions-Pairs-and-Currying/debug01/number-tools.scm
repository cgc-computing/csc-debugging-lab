; number-tools.scm
; Small utilities over lists of numbers built with higher-order
; procedures: squares maps a function over a list, evens keeps only the
; even numbers, and sum-evens adds them up.

(define (square x)
  (* x x))

(define (squares lst)
  (map square lst))

(define (evens lst)
  (map even? lst))

(define (sum-evens lst)
  (apply + (evens lst)))
