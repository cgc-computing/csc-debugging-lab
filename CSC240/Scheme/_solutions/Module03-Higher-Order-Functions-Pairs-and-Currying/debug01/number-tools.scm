; number-tools.scm
; Small utilities over lists of numbers built with higher-order
; procedures: squares maps a function over a list, evens keeps only the
; even numbers, and sum-evens adds them up.

(define (square x)
  (* x x))

(define (squares lst)
  (map square lst))

(define (keep-if pred lst)
  (cond ((null? lst) '())
        ((pred (car lst)) (cons (car lst) (keep-if pred (cdr lst))))
        (else (keep-if pred (cdr lst)))))

(define (evens lst)
  (keep-if even? lst))

(define (sum-evens lst)
  (apply + (evens lst)))
