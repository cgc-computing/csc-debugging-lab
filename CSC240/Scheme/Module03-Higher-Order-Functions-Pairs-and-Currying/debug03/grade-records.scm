; grade-records.scm
; A grade record is a pair (name . score) built with cons. my-reduce
; folds a list from the right: the combining procedure receives the
; current element and the result accumulated so far. total-score and
; top-score use my-reduce over a list of records.

(define (make-record name score)
  (cons name score))

(define (record-name r)
  (car r))

(define (record-score r)
  (car (cdr r)))

(define (my-reduce f init lst)
  (cond ((null? lst) init)
        (else (f (my-reduce f init (cdr lst)) (car lst)))))

(define (total-score records)
  (my-reduce (lambda (r acc) (+ (record-score r) acc))
             0
             records))

(define (top-score records)
  (my-reduce (lambda (r acc)
               (if (> (record-score r) acc)
                   (record-score r)
                   acc))
             0
             records))

(define roster
  (list (make-record 'ana 92)
        (make-record 'ben 85)
        (make-record 'cy 78)))
