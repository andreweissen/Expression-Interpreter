/**
 * SubExpression.cpp
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#include <iostream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "negation.h"
#include "ternary.h"
#include "equals.h"
#include "and.h"
#include "or.h"
#include "greaterthan.h"
#include "lessthan.h"

/**
 * Parameterized constructor simply sets the associated values of the
 * <code>Expression</code> types of <code>left</code> and <code>right</code>.
 * @param left <code>Expression</code> type
 * @param right <code>Expression</code> type
 */
SubExpression::SubExpression(Expression* left, Expression* right) {
  this->left = left;
  this->right = right;
}

/**
 * Though much of this method remains intact as implemented in the Module 3
 * codebase, a number of small modifications were made to handle ternary and
 * negation operations, as denoted in the Project 2 rubric. Further, in
 * accordance with the author's Project 1 submission, the use of nested
 * <code>switch</code> blocks was discouraged and handled via the use of a
 * private helper method, namely, <code>SubExpression::determineType()</code>.
 * <br />
 * <br />
 * In order to handle ternary operations in accordance with the unique order set
 * in the project rubric (namely, true value : false value ? condition), a third
 * <code>Expression</code> type container variable, <code>condition</code>, is
 * declared and defined, with a <code>switch</code> statement used to grab the
 * three values and pass them to a special three parameter <code>Ternary</code>
 * <code>SubExpression</code> child class. Negation is handled in the same block
 * and though it is passed both <code>left</code> and <code>right</code>, only
 * the value of <code>left</code> is inverted/negated in the appropriate class.
 *
 * @param iss <code>istringstream</code> reference
 * @return <code>Expression</code> type, <tt>SubExpression::determineType</tt>
 */
Expression* SubExpression::parse(istringstream& iss) {

  // Declarations
  Expression* left;
  Expression* right;
  Expression* condition;
  char operation, paren;

  // Grab first value (either value to negate, value when true, or left value)
  left = Operand::parse(iss);

  // Move next char (an operator) into char container variable
  iss >> operation;

  switch (operation) {
    case '!':
      iss >> paren; // ')'
      right = NULL; // Dummy param, only left is negated (since ! comes last)
      return new Negation(left, right);
    case ':':
      right = Operand::parse(iss);          // Value when false
      iss >> paren;                         // '?'
      condition = Operand::parse(iss);      // Condition
      iss >> paren;                         // ')'
      return new Ternary(left, right, condition);
    default:
      right = Operand::parse(iss);          // Right hand operand value
      iss >> paren;                         // ')'
      return SubExpression::determineType(operation, left, right);
  }
}

/**
 * This method is the only new method contained in the class, and is primarily
 * used to determine the proper type of operator type to instantiate and return.
 * It was based on a similar helper method employed in the author's Project 1
 * submission, and was moved to a separate method to prevent there from being a
 * pair of nested <code>switch</code> statements in the body of
 * <code>SubExpression::parse()<code>.
 *
 * @param operation <code>char</code> operator representation
 * @param left <code>Expression</code> type, value of <code>left</code>
 * @param right <code>Expression</code> type, value of <code>right</code>
 * @return <code>Expression</code> type (operator)
 */
Expression* SubExpression::determineType(char operation, Expression* left,
    Expression* right) {

  switch (operation) {
    case '&':
      return new And(left, right);
    case '/':
      return new Divide(left, right);
    case '=':
      return new Equals(left, right);
    case '>':
      return new GreaterThan(left, right);
    case '<':
      return new LessThan(left, right);
    case '-':
      return new Minus(left, right);
    case '|':
      return new Or(left, right);
    case '+':
      return new Plus(left, right);
    case '*':
      return new Times(left, right);
    default:
      return 0; // Should be NULL?
  }
}