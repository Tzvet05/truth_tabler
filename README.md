# truth_tabler

A graphical truth table builder & displayer

For this program to work, your inputs must conform to the following syntax.
Logical operations are to be written as follow :

  operator(param1, param2, ..., paramn)

where "operator" is a supported logic operator;
"param" are input bits or other logic operators with their own parameters.
Conforming to the comas and spaces is not required.

Example :

  xor(xor(A2, B2), and(A1, B1), and(xor(A1, B1), and(A0, B0)))

Supported logical operators:
- not
- or
- nor
- xor
- xnor
- and
- nand

Limitations :
You shall not provide more than 64 different input bits. This restriction is due to the fact that all different combinations of input bits are determined using a decrementing size_t, which is encoded on 64 bits (I consider it enough since it provides you over 18 quadrillions different input combinations, and I wasn't willing to take time to hande more than that).

This work is in the public domain.
