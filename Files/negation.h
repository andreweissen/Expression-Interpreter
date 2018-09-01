/**
 * Negation.h
 * @author Andrew Eissen
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef NEGATION_H
#define NEGATION_H

#include "subexpression.h"

/**
 * This class is a subclass of <code>SubExpression</code>, one of the default
 * classes included in the Module 3 study. As per that class's specifications,
 * this class implements and overrides the
 * <code>Expression::evaluate()</code> method, returning the negated value of
 * the <code>left</code> expression parameter included via the constructor.
 *
 * @author Andrew Eissen
 * @see SubExpression
 */
class Negation : public SubExpression {
 public:

  /**
   * Parameterized constructor, extends <code>SubExpression</code>
   * @param left <code>Expression</code> type
   * @param right <code>Expression</code> type
   */
  Negation(Expression* left, Expression* right) : SubExpression(left, right) {}

  /**
   * Overridden method initially specified by class <code>Expression</code>. It
   * returns the negated value of <code>left</code> as an <code>int</code>.
   *
   * @return int <code>left</code>'s negated value
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return !(left->evaluate());
  }
};
#endif  // NEGATION_H