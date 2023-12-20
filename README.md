Truth tabler - A graphical truth table builder and displayer

For this program to work, the inputted expression must conform to the following syntax.

Logical operations must be written as follow :

`operator(param1, param2, ..., paramn)`

Where :
- `operator` is a supported logic operator (see list below);
- `param` are either input bits or other logic operators with their own parameters.

Logic operators must have their parameters inbetween parenthesis, all separated by a comma. The syntax is entirely loose on whitespace caracters. Input bits' names are sensitive to the case, but logic operators are not. Input bits' names must not contain parenthesis ('(', ')'), commas (','), withespaces (' ' and 9 to 13 in ASCII table), nor can they be logic operator names (see list below).

Valid syntax example :

- `xoR( NAND(LoReM, ipsum), xor  (dolor,  Ipsum,sIt),aNd ( OR(AMET,sIt, LoReM ), and(NOt ( AMET ),dolor)  ))`

In this example, there are 6 input bits (`LoReM`, `ipsum`, `Ipsum`, `dolor`, `sIt`, `AMET`). This leads to 2^6 = 64 different input combinations.

Invalid syntax example :

- `xor(lorem ipsum` : unclosed parenthesis and missing comma between parameters
- `nor(dol(or, sit)` : parenthesis inside input bit name / opened parenthesis not preceded by supported logic operator (`dol` is not a supported logic operator (see list below))
- `huh(amet, consectetur)` : `huh` is not a supported logic operator (see list below)
- `xnor(adip,isci , elit)` : comma inside input bit name (parsed as 3 parameters : `apid`, `isci` and `elit`, while one would have wanted 2 : `adip,isci` and `elit`)

Supported logical operators:
- `not`
- `or`
- `nor`
- `xor`
- `xnor`
- `and`
- `nand`

The `not` logic operator must be provided with only 1 parameter.
All other logic operators must be provided with at least 2 parameters, and up to 18,446,744,073,709,551,615 parameters.

Limitations :
- An input must not contain more than 64 different input bits. This restriction is due to the fact that all different combinations of input bits are determined using a decrementing `size_t`, which is encoded on 64 bits (I consider it enough since with 64 input bits the program would already need to display 18,446,744,073,709,551,615 (2⁶⁴) input combinations).
- Logic operators are limited to 18,446,744,073,709,551,615 maximum parameters. This is due to the input of a logic operator, determined as the sum of all its parameters, being stored in a `size_t`. It can actually handle 18,446,744,073,709,551,615 maximum `True` parameters, so it could handle more than 18,446,744,073,709,551,615 parameters if some were always `False`, but for safety reasons, you must not provide more than 18,446,744,073,709,551,615 parameters per logic operator regardless of their state.
- Imbricated logic operators execute recursive functions an amount of times equal to their imbricated depth. Be aware that the higher depth of the input expression might overflow the stack if it is too high. This means that an input like `operator(operator(operator(operator(...))))` cannot go indefinitely.

This work conforms to the fourth version of school 42's internal norm "The Norm V4".

This work is in the public domain.
