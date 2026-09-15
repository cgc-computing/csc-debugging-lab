; lat-functions.scm
; Predicates over lists of atoms in the style of The Little Schemer:
; atom? tells atoms from lists, lat? checks that a list holds only
; atoms, and member? asks whether an atom appears in a lat.

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (lat? l)
  (cond ((null? l) #t)
        ((atom? (car l)) (lat? (cdr l)))
        (else #f)))

(define (member? a lat)
  (cond ((eq? (car lat) a) #t)
        ((null? lat) #f)
        (else (member? a (cdr lat)))))
