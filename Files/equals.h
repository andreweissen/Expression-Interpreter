/**
 * Equals.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef EQUALS_H
#define EQUALS_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, returning a true value if the
 * equality comparison expression evaluates to true.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class Equals : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  Equals(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns a true value if the resultant equality comparison operation
   * successfully evaluates to true.
   *
   * @return int comparison of <code>left</code> and <code>right</code>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() == right->evaluate();
  }
};
#endif  // EQUALS_H