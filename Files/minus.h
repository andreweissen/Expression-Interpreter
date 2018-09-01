/**
 * Minus.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef MINUS_H
#define MINUS_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, which returns an appropriate
 * <code>int</code> value derived from the subtraction of <code>right</code>'s
 * value from that of <code>left</code>.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class Minus : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  Minus(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns the resultant value of subtraction of value of <code>right</code>
   * from the value of <code>left</code>.
   *
   * @return int Result of subtraction between <tt>left</tt> and <tt>right</tt>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() - right->evaluate();
  }
};
#endif  // MINUS_H