; list-builders.scm
; Three procedures that build new lists of atoms: add-to-end puts an
; atom at the back of a lat, insertR inserts an atom to the right of
; the first occurrence of another, and my-reverse reverses a lat.

(define (add-to-end a lat)
  (cond ((null? lat) (list a))
        (else (cons (car lat) (add-to-end a (cdr lat))))))

(define (insertR new old lat)
  (cond ((null? lat) '())
        ((eq? (car lat) old) (cons old (cons new (cdr lat))))
        (else (cons (car lat) (insertR new old (cdr lat))))))

(define (my-reverse lat)
  (cond ((null? lat) '())
        (else (add-to-end (car lat) (my-reverse (cdr lat))))))
