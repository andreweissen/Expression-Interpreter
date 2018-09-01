/**
 * Times.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef TIMES_H
#define TIMES_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, which returns an appropriate
 * <code>int</code> value derived from the multiplication of <code>left</code>'s
 * value by that of <code>right</code>.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class Times : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  Times(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns the resultant value of multiplication of the value of
   * <code>left</code> by the value of <code>right</code>.
   *
   * @return int Result of multiplication b/w <tt>left</tt> and <tt>right</tt>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() * right->evaluate();
  }
};
#endif  // TIMES_H