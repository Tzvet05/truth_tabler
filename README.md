Truth tabler - A graphical truth table builder and displayer

For this program to work, your inputs must conform to the following syntax.

Logical operations must be written as follow :

`operator(param1, param2, ..., paramn)`

Where :
- `operator` is a supported logic operator;
- `param` are either input bits or other logic operators with their own parameters.

Input bits' names are sensitive to the case, but logic operators are not. Conforming to the parenthesis syntax is necessary. Conforming to the comas and spaces is not required, but you will need a caracter to separate your input bits' names.

Example :

`xor(nand(A2, B2), xor(B0, B2, B1), and(or(A1, B1, A0), and(not(A0), B0)))`

In this example, there are 6 input bits (`A0`, `A1`, `A2`, `B0`, `B1`, `B2`). This leads to 2^6 = 64 different input combinations.

Supported logical operators:
- `not`
- `or`
- `nor`
- `xor`
- `xnor`
- `and`
- `nand`

The `not` logic operator must be provided with only 1 parameter.
All other logic operators must be provided with at least 2 parameters, and up to 18446744073709551615 parameters.

Limitations :
- An input must not contain more than 64 different input bits. This restriction is due to the fact that all different combinations of input bits are determined using a decrementing `size_t`, which is encoded on 64 bits (I consider it enough since the program would need to display over 18 quadrillion input combinations).
- Logic operators are limited to 18446744073709551615 maximum parameters. This is due to the input of a logic operator, determined as the sum of all its parameters, being stored in a `size_t` (2^64 = 18446744073709551615). It can actually handle 18446744073709551615 maximum `True` parameters, so it could handle more than 18446744073709551615 parameters if some were always `False`, but for safety reasons, you must not provide more than 18446744073709551615 parameters per logic operator regardless of their state.
- Imbricated logic operators execute recursive functions an amount of times equal to their imbricated depth. Be aware that the maximum depth of the input might overflow the stack if too large. This means that an input like `operator(operator(operator(operator(...))))` cannot go indefinitely.

This work conforms to the fourth version of school 42's internal norm "The Norm V4".

This work is in the public domain.
