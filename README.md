# Reverse-Polish-Notation

Reverse Polish Notation
Reverse Polish notation (RPN) is a method for representing expressions in which the operator symbol is placed after the arguments being operated on. Polish notation, in which the operator comes before the operands, was invented in the 1920s by the Polish mathematician Jan Lucasiewicz. In the late 1950s, Australian philosopher and computer scientist Charles L. Hamblin suggested placing the operator after the operands and hence created reverse polish notation.

![polish](https://user-images.githubusercontent.com/73845925/225279136-737fd4f7-2443-475f-b5fd-b4abef991938.png)

For example, the following RPN expression will produce the sum of 2 and 3, namely 5: 2 3 +.

Reverse Polish notation, also known as postfix notation, contrasts with the "infix notation" of standard arithmetic expressions in which the operator symbol appears between the operands.

RPN has the property that brackets are not required to represent the order of evaluation or grouping of the terms. RPN expressions are simply evaluated from left to right and this greatly simplifies the computation of the expression within computer programs. As an example, the arithmetic expression (3+4)×5 can be expressed in RPN as 3 4 + 5 ×.

In practice RPN can be conveniently evaluated using a stack structure. Reading the expression from left to right, the following operations are performed:

1. If a value appears next in the expression, push this value on to the stack.

2. If an operator appears next, pop two items from the top of the stack and push the result of the operation on to the stack.

A standard infix arithmetic expression can be converted to an RPN expression using a parsing algorithm as a recursive descent parse.

RPN is used in Hewlett Packard and some Texas Instruments calculators and internally in some computer languages.
