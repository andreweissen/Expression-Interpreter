/**
 * And.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef AND_H
#define AND_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, returning a true value if the
 * logical <code>&&</code> expression evaluates to true.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class And : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  And(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns a true value if the resultant logical <code>&&</code> comparison
   * evaluates to true.
   *
   * @return int "and" comparison of <code>left</code> and <code>right</code>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return left->evaluate() && right->evaluate();
  }
};
#endif  // AND_H