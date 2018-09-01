/**
 * SubExpression.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef SUBEXPRESSION_H
#define SUBEXPRESSION_H

#include "expression.h"

/**
 * This class is one of two that extend <code>Expression</code>, the other being
 * <code>Operand</code>. It is used to create node objects used to fill out the
 * arithmetic expression tree, identifying the type of operator used and
 * generating a new <code>SubExpression</code> subclass instance via a set of
 * <code>switch</code> statements.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @see Expression
 */
class SubExpression : public Expression {
 public:

  /**
   * Parameterized constructor
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  SubExpression(Expression* left, Expression* right);

  /**
   * Static method used to divine the type of operator element encountered, used
   * to create node objects in the arithmetic expression tree. Uses a dedicated
   * <code>switch</code> block to handle negation and ternary operations, and
   * invokes private helper method, <code>SubExpression::determineType()</code>,
   * to return a relevant operator subclass instance.
   *
   * @param iss Line-based <code>istringstream</code> reference
   * @return Expression type
   */
  static Expression* parse(istringstream& iss);

 protected:
  Expression* left;
  Expression* right;

 private:

  /**
   * This helper method is marked as private as it is only used within the body
   * of <code>SubExpression::parse()</code> to divine the type of operator
   * subclass instance to create. It was made a separate method to ensure that
   * <code>SubExpression::parse()</code> does not contain a set of nested
   * <code>switch</code> statement blocks.
   *
   * @param operation <code>char</code> representing operator
   * @param Expression* left <code>Expression</code> type
   * @param Expression* right <code>Expression</code> type
   * @return Expression* Type of subclass operator instance
   */
  static Expression* determineType(char operation, Expression* left,
    Expression* right);
};
#endif  // SUBEXPRESSION_H