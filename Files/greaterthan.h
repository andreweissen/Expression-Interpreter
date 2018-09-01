/**
 * GreaterThan.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef GREATERTHAN_H
#define GREATERTHAN_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, returning a true value if the
 * <code>left</code> value is greater than that of the <code>right</code>
 * value.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class GreaterThan : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  GreaterThan(Expression* left, Expression* right)
      : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns a true value if the value of <code>left</code> is greater than that
   * of the <code>right</code> value.
   *
   * @return int comparison of <code>left</code> and <code>right</code>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() > right->evaluate();
  }
};
#endif  // GREATERTHAN_H