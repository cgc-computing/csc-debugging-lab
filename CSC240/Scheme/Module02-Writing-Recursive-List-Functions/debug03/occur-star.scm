; occur-star.scm
; Counting occurrences of an atom. occur counts in a flat list of atoms;
; occur* counts in an arbitrarily nested list, following the *-function
; pattern from The Little Schemer, chapter 6.

(define (atom? x)
  (and (not (pair? x)) (not (null? x))))

(define (occur a lat)
  (cond ((null? lat) 0)
        ((eq? (car lat) a) (+ 1 (occur a (cdr lat))))
        (else (occur a (cdr lat)))))

(define (occur* a l)
  (cond ((null? l) '())
        ((atom? (car l))
         (cond ((eq? (car l) a) (+ 1 (occur* a (cdr l))))
               (else (occur* a (cdr l)))))
        (else (occur* a (cdr l)))))
