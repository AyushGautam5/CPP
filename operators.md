Operators are symbols that are used for mathematical and logical computation on operands.

They are of three types(based on number of operands):

1. Unary: Requires a single operand. E.g, X++, ++X, etc.
2. Binary: Require two operands. E.g, a+b, a*b, etc.
3. Ternary: Require three operands. E.g, a ? b: c

## Types of Operators (Based on their FUNCTIONALITY)

### Arithmatic Operators

They are operators which are used to perform arithmetic or mathematical operations.

Example: +, -, *, /, %, etc.

The division operator of C++ performs so-called integer division. This means the answer is rounded to an integer (towards 0).
Hence 7 / 3 = 2, with the remainder 1, and -7 / 3 = -2.

### Assignment Operators

They are used to assign values to variables.
Example, = ,+= ,-= , *= , /= ,etc.

Remember it’s denoted by =. That is different from the equality operator ==.

### Relational Operators

They are used to compare values and determine if they are equal or not.
The value is either 0 or 1 (true or false).

### Logical Operators

They are used to perform logical operations on variables and value.
**Note** : 0 denotes false and everything other than 0 denotes true.

AND (&&)
OR (||)
NOT (!)

### Increment and Decrement Operators

These are operators that are used to increment or decrement the value of a variable.

++ denotes increment by 1
-- denotes decrement by 1

If we apply the operator before the variable, like ++a or --b, then first the value of the variable is changed by 1 and then the expression is evaluated.

If we apply the operator after the variable, like a++ or b--, then first the expression is evaluated and then the value of the variable is changed by 1.

### Bitwise operators

They are used to perform bitwise operations on variables and values. Bitwise operations are used to manipulate individual bits of a binary number. Decimal numbers are represented using binary numbers, which are made up of 1s and 0s. Bitwise operators are used to perform operations on these binary numbers.

You can learn more about bitwise operators by visiting [Bitwise](https://bitwisecmd.com/).
