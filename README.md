### CMSC 330 Expression Interpreter ###

#### Overview ####

This project, created for CMSC 330 Advanced Programming Languages, is an expression interpreter written in C++ that accepts a formatted text file and performs the operations written in the interpreter grammar. Though some of the files were provided partially constructed to give students unfamiliar with C++ a hand in completing the assignment, the author went about refactoring these classes to make them more efficient and readable. The project makes use of Ccdoc, a variation of Javadoc for use by C family languages.

It was submitted on August 9, 2018 and received a grade of 100%. Images of the program in action are provided in the appropriate folder, along with test text files and the C++ files themselves. The grammar in question is included below in Backus–Naur form:

```
<program> → <exp> , <assigns> ;
<exp> → ( <operand> <op> <operand> )
<operand> → <literal> | <variable> | <exp>
<assigns> → <assigns> , <assign> | <assign>
<assign> → <variable> = <literal>
<exp> -> '(' <operand> <op> <operand> ')' |
 '(' <operand> ':' <operand> '?' <operand> ')' |
 '(' <operand> '!' ')'
<op> -> '+' | '-' | '*' | '/' | '>' | '<' | '=' | '&' | '|'

```