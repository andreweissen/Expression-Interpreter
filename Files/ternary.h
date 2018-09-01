/**
 * Ternary.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef TERNARY_H
#define TERNARY_H

#include "expression.h"
#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, making use of its own subclass-
 * specific field condition, an <code>Expression</code> instance, to represent
 * the initial condition upon which the resultant true or false return value
 * depends.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class Ternary : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   * @param condition <code>Expression</code> type
   */
  Ternary(Expression* left, Expression* right, Expression* condition)
      : SubExpression(left, right) {
    this->condition = condition;
  }

  /**
   * Overridden method initially specified by <code>Expression</code>. It
   * returns the value of <code>left</code> if <code>Ternary.condition</code> is
   * true and returns the value of <code>right</code> if false.
   *
   * @return int <tt>left</tt>'s value if true, <tt>right</tt>'s if false
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return condition->evaluate() ? left->evaluate() : right->evaluate();
  }

 private:
  Expression* condition;
};
#endif  // TERNARY_H