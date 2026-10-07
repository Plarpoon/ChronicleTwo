# MWCC matching notes

Game translation units use MWCC 3.0-011126 with `-O3,p`, read-only strings,
exceptions and RTTI disabled, and `divbyzerocheck on` in the shared build
flags. A local `divbyzerocheck` pragma therefore needs a demonstrated change
in generated code; the option itself is already enabled for every game unit.

MWCC generates constructor vtable writes and C++ symbol names from class
definitions. Keep member functions and constructors in C++ form so the
compiler emits those symbols. If a natural form differs from retail, retain
it under `NONMATCHING` and use `INCLUDE_ASM` for the active function until its
object score is zero.

Compare complete objects as well as individual functions. A matching function
body can still alter a unit through an emitted inline helper, a static
initializer, or a differently sized data section. The PAL executable verifier
checks the final linked layout after the object comparison.
