# Postfix Calc
> This calculates the value of the input postfix notation expression

![](/PostfixCalc/postfixCalc.png)

## Program Map
> Use this to follow the explanation below

![](/PostfixCalc/postfixCalc_Eval.png)

## Explanation
> Note: Unfortunately Github markdown does not support HTML text coloring...
### <span style="color:cyan">Input Reading / Initial Logic (Blue)</span>
1. Push 0 onto stack
2. The start of the programs main while loop
    - First reads in a character (from now on reffered to as **token**), if no input left break out of loop and go to <span style="color:cyan">blue 2a</span>, else go to <span style="color:cyan">blue 3</span>
    - 2a - Pop the initial 0 from the stack and then output the calculated result of the input equation, go to program end (<span style="color:cyan">blue 2b</span>)
3. Push 48 (0) to stack to check if **token** is a digit or operator
4. If **token** is a digit subtract 48 from digit char value (i.e. 49 (1) - 48 = 1) and go to <span style="color:red">red 1</span>
    - This is done because we need to read all input as a char so we can process operators, but in order to do math, we need digit's as their integer value.
5. Else **token** is an operator, so go to <span style="color:orange">orange 1</span>

### <span style="color:red">Operand Logic (Red)</span>
1. Roll stack to place char value of input on top, then pop it off stack (discard)
2. Roll stack again to place integer value of input under the initial 0 (operand stack)
    - 2a - Change pointer to loop back to <span style="color:cyan">blue 2</span>

### <span style="color:orange">Intermission (Orange)</span>
1. Pop leftover meaningless value that resulted from earlier checks
2. Push 3 onto the stack twice
    - These are used to guide the program through <span style="color:orange">orange 2a and b</span> to <span style="color:magenta">purple 1</span>

### <span style="color:magenta">Operator Check (Purple)</span>
1. Push 42 ('*') onto the stack, if operator is *, pop operator from stack, and go to <span style="color:lime">green 1</span>
2. Push 43 ('+') onto the stack, if operator char value is > 43, continue to <span style="color:magenta">purple 3</span>
    - Else, operator is + so pop operator from stack, and go to <span style="color:lime">green 2</span>
3. Push 45 ('-') onto the stack, if operator is -, pop operator from stack, and go to <span style="color:lime">green 3</span>
    - 3a - Operator is none of the above, thus it's '/', so pop operator from stack and go to <span style="color:lime">green 4</span>

### <span style="color:lime">Math (Green)</span>
1. Roll stack to got the top two operands from the operator stack (which we maintained by keeping under the initial pushed 0), then perform (op1 * op2) and continue to <span style="color:lime">green 5</span>
2. Roll stack to got the top two operands from the operator stack, then perform (op1 + op2) and continue to <span style="color:lime">green 5</span>
3. Roll stack to got the top two operands from the operator stack, then perform (op1 - op2) and continue to <span style="color:lime">green 5</span>
4. Roll stack to got the top two operands from the operator stack, then perform (op1 / op2) and continue to <span style="color:lime">green 5</span>
5. Roll stack to place the result of the previous operation onto the top of the operand stack (right under the 0), and continue back to <span style="color:cyan">blue 2</span>

## Limitations
Does not handle multi-digit numbers, negative numbers, or exponents in input.
