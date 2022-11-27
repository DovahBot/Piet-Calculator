# Piet Calculator
> An infix to postfix converter and calculator written in the esoteric language Piet

## Table of Contents

1. [Programs](#programs)
   1. [Infix To Postfix Converter](#infix-to-postfix-converter)
   2. [Postfix Calculator](#postfix-calculator)
2. [About Piet](#about-piet)
3. [Project Notes](#project-notes)
   1. [Limitations](#limitations)
4. [How to Run](#how-to-run)
5. [Contributing](#contributing)
6. [License](#license)

## Programs

### Infix To Postfix Converter

> This converts an expression from infix to postfix notation
> <br>**See a detailed explanation [here](/InfixToPostfix/README.md)**
![](/InfixToPostfix/infixToPostfix.png)
```
Input: 1+(3-4)*9/2
Output: 134-9*2/+
```

### Postfix Calculator

> This takes a postfix notation expression as input and calculates the result
> <br>**See a detailed explanation [here](/PostfixCalc/README.md)**
![](/PostfixCalc/postfixCalc.png)
```
Input: 134-9*2/+
Output: -3
```

## About Piet

Piet is an esoteric programming language, named after the artist Piet Mondrian, in which every instruction is represented by a transition between colors and hues.

[Read more about Piet here!](https://www.dangermouse.net/esoteric/piet.html)

## Project Notes

This calculator begins with a conversion to postfix as it is significantly easier **in Piet** to calculate the value of a postfix expression rather than an infix one.

I initially imagined this calculator to be confined within a single image, instead of one program to convert from infix to postfix and another to calculate. However, after making significant progress on the former I realized without access to anotherr stack to store program output for later, this would be very difficult.

I do think it's feasible, but would require significant stack manipulation. Maybe it'll be a future endeavor...

### Limitations

Currently, these programs do not handle multi-digit numbers, negative numbers, or exponents as input. Also, any decimals are truncated.

## How to Run

1. Either clone this repo or download the png's from the latest release.
    > Note: Codel size of release png is important when running.
2. I recommend using the [Pietron IDE](https://github.com/dnek/pietron) to run as it has a useful debugger where you can step through to better understand the program if you wish.
3. Open either infixToPostfix_Codel_[1](/Release/infixToPostfix_Codel_1.png) or _[20](/Release/infixToPostfix_Codel_20.png) and enter that value when prompted for codel size.
   1. Input an infix expression, run, and copy the output.
4. Then follow step 3 for postfixCalc_[1](/Release/postfixCalc_Codel_1.png) or _[20](/Release/postfixCalc_Codel_20.png).
   1. Input the return value from 3.1 and run to calculate the value.

## Contributing

Please open issues to discuss bugs or ideas 😁

## License

[MIT](https://choosealicense.com/licenses/mit/)