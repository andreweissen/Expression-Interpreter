/**
 * Plus.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef PLUS_H
#define PLUS_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, which returns an appropriate
 * <code>int</code> value derived from the addition of <code>left</code>'s value
 * and that of <code>right</code>.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @see SubExpression
 */
class Plus : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  Plus(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns the resultant sum of addition between value of <code>left</code>
   * and the value of <code>right</code>.
   *
   * @return int Result of addition between <tt>left</tt> and <tt>right</tt>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() + right->evaluate();
  }
};
#endif  // PLUS_H