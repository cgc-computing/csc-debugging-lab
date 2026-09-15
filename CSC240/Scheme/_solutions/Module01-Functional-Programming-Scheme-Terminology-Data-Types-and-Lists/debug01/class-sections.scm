; class-sections.scm
; Two lab sections are kept as lists of student names. merge-sections
; combines them into one roster; count-students and first-student are
; small helpers that work on any list of atoms.

(define morning '(ana ben carlos))
(define afternoon '(dee eli))

(define (merge-sections first-section second-section)
  (append first-section second-section))

(define (count-students lat)
  (cond ((null? lat) 0)
        (else (+ 1 (count-students (cdr lat))))))

(define (first-student lat)
  (car lat))
