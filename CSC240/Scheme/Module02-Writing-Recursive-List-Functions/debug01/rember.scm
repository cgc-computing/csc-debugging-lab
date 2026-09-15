; rember.scm
; rember removes the first occurrence of an atom from a list of atoms.
; firsts collects the first element of each inner list. Both follow the
; recursion patterns from The Little Schemer, chapter 3.

(define (rember a lat)
  (cond ((null? lat) '())
        ((eq? (car lat) a) (cdr lat))
        (else (rember a (cdr lat)))))

(define (firsts l)
  (cond ((null? l) '())
        (else (cons (car (car l)) (firsts (cdr l))))))
