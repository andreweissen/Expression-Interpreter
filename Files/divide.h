/**
 * Divide.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef DIVIDE_H
#define DIVIDE_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, which returns an appropriate
 * <code>int</code> value derived from the division of <code>left</code>'s
 * value by that of <code>right</code>.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class Divide : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  Divide(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns the resultant value of division of the value of <code>left</code>
   * by the value of <code>right</code>.
   *
   * @return int Result of division between <tt>left</tt> and <tt>right</tt>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() / right->evaluate();
  }
};
#endif  // DIVIDE_H