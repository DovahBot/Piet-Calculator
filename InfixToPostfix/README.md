# Infix to Postfix
> This converts the input expression from infix to postfix notation

The following Piet program resembles the [Shunting Yard Algorithm](https://en.wikipedia.org/wiki/Shunting_yard_algorithm)


![](/InfixToPostfix/infixToPostfix.png)

## Program Map
> Use this to follow the explanation below
![](/InfixToPostfix/infixToPostfix_Eval.png)

## Explanation
> Note: Unfortunately Github markdown does not support HTML text coloring...
### <span style="color:cyan">Input Reading / Initial Logic (Blue)</span>
1. Push 0 onto stack
2. The start of the programs main while loop
    - First reads in a character (from now on reffered to as **token**), if no input left break out of loop and go to <span style="color:lime">green 1</span>, else go to <span style="color:cyan">blue 3</span>
    - 2a - Ensures CC is set to left
3. Push 48 (0) to stack to check if **token** is a digit or operator
4. If **token** is an operator (or parenthesis) go to <span style="color:red">red</span>
5. Else input char is a digit, so output the number and loop back to <span style="color:cyan">blue 2</span>

### <span style="color:red">Parenthesis Check (Red)</span>
1. Push 40 ('(') onto the stack, if **token** is left paren go to <span style="color:red">red 1a</span>
    - 1a - Push left paren onto operator stack (which I define as everything below the 0 on stack) and continue to <span style="color:cyan">blue 2</span>
    - Else, continue to <span style="color:red">red 2</span>
2. Push 41 (')') onto the stack, if **token** is right paren go to <span style="color:red">red 3</span>
    - If **token** is not right paren, then **token** is an operator, go to <span style="color:red">red 4</span>
3. Pop value 'operator' from operator stack, if 'operator' is not left paren, output 'operator' and loop back to <span style="color:red">3</span> by following <span style="color:red">3a,b</span>
    - If 'operator' is a left paren, break out of the <span style="color:red">3</span> loop and go to <span style="color:red">red 5</span>
4. Line break to go to <span style="color:magenta">purple</span>
5. Go back to <span style="color:cyan">blue 2</span>

### <span style="color:magenta">Operator Stack Check (Purple)</span>
1. Roll stack to get the top element *op1* from the operator stack (that we've maintained by keeping under the initial pushed 0), go to <span style="color:magenta">purple 2</span>
    - 1a - Ensures CC is set to left
2. Check if operator stack is empty, if empty go to <span style="color:magenta">purple 2a</span>
    - 2a - Push **token** to the operator stack and continue back to <span style="color:cyan">blue 2</span>
3. Push 40 ('(') onto the stack, if *op1* is left paren go to <span style="color:magenta">purple 3a</span>
    - 3a - Push 'token' to the operator stack and continue back to <span style="color:cyan">blue 2</span>
    - Else *op1* is not left paren, so continue to <span style="color:orange">orange</span>

### <span style="color:orange">Operator Logic (Orange)</span>
1. Roll stack to place **token** on the top
2. Push 42 ('*') onto the stack, if **token** is *, go to <span style="color:orange">orange 4</span>
3. Else Push 47 ('/') onto the stack, if **token** is /, go to <span style="color:orange">orange 4</span>
    - Else **token** precedence is <= to that of *op1*, thus go to <span style="color:orange">orange 7</span>
4. Roll stack to place *op1* on the top
5. Push 43 ('+') onto the stack, if *op1* is +, go to <span style="color:orange">orange 5a</span>
    - Else, *op1* is not +, go to <span style="color:orange">orange 6</span>
    - 5a - Roll stack to place **token** on the top, then Push **token** to the operator stack and continue back to <span style="color:cyan">blue 2</span>
6. Push 45 ('-') onto the stack, if *op1* is -, go to <span style="color:orange">orange 6a</span>
    - 6a - Continue to <span style="color:orange">orange 5a</span>
7. Roll stack to place *op1* on the top, go to <span style="color:orange">orange 8</span>
8. Output operator, continue to <span style="color:magenta">purple 1a</span>

### <span style="color:lime">Post Input Processing (Green)</span>
1. Proceed down to <span style="color:lime">green 2</span>
2. Roll stack to get the top element *op1* from the operator stack. If *op1* > 1 (meaning *op1* exists and is not the initial pushed 0) go to <span style="color:lime">green 2a</span>
    - Else go to <span style="color:lime">green 3</span>
    - 2a - Stack is empty, program end
3. Push 40  ('('), if *op1* - 40 > 1 (meaning *op1* is not left or right paren), go to <span style="color:lime">green 4</span>
    - Else *op1* is a parenthesis, go to <span style="color:lime">green 3a</span>
    - 3a - Parenthesis should have been handled by <span style="color:red">red</span> loop, so unmatched parens, input is not valid, output '?' and end program (<span style="color:lime">green 3b</span>)
4. Output operator, continue to <span style="color:lime">green 4a</span>
    - 4a - Correct CC and go back to <span style="color:lime">green 2</span>

## Limitations
Does not handle multi-digit numbers, negative numbers, or exponents.