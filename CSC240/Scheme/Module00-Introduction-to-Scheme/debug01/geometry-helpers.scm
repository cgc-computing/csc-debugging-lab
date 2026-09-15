; geometry-helpers.scm
; A few small numeric procedures for a first Scheme session:
; squaring, averaging, converting temperatures, the length of the
; hypotenuse of a right triangle, and the distance between two numbers.

(define (square x)
  (* x x))

(define (average a b)
  (/ (+ a b) 2))

(define (fahrenheit->celsius f)
  (* (- f 32) (/ 5 9)))

(define (hypotenuse a b)
  (sqrt (+ (square (a)) (square b))))

(define (distance a b)
  (if (> a b)
      (- a b)
      (- b a)))
