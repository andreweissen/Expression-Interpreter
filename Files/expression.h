/**
 * Expression.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef EXPRESSION_H
#define EXPRESSION_H

/**
 * This is an abstract class used as the base class of the arithmetic expression
 * tree in the inheritance hierarchy. This class has a pair of subclasses that
 * inherit its <code>Expression::evaluate()</code> method, namely
 * <code>SubExpression</code> and <code>Operand</code>, each of which have
 * further subclasses that implement the <code>Expression::evaluate()</code>
 * method in relation to their associated operations and purposes.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 */
class Expression {
 public:

  /**
   * Pure virtual method/function is set to 0 so as to force other classes to
   * derive a subclass and implement the method in order to make use of it.
   * Basically, the class cannot be instantiated without the method being
   * implemented.
   *
   * @return int An <code>int</code> value related to an operation/comparison
   * @see <a href="https://stackoverflow.com/questions/3339302">SO Thread</a>
   */
  virtual int evaluate() = 0;
};
#endif  // EXPRESSION_H