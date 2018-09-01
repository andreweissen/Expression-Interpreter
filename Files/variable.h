/**
 * Variable.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef VARIABLE_H
#define VARIABLE_H

#include "operand.h"

/**
 * This class is one of two subclasses of <code>Operand</code>, the other being
 * <code>Literal</code>. This particular class handles leaf nodes that contain
 * variables. Its sole method is the overridden
 * <code>Expression::evaluate()</code>, used in this context to extract an
 * <code>int</code> value associated with <code>string</code> <code>name</code>
 * from the <code>elements</code> <code>vector</code> structure.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @see Operand
 */
class Variable : public Operand {
 public:

  /**
   * Parameterized constructor
   * @param name <code>string</code>
   */
  Variable(string name) {
    this->name = name;
  }

  /**
   * <code>Expression</code>'s pure virtual method requiring implementation by
   * subclasses. This particular incarnation returns the <code>int</code> value
   * stored in the <code>elements</code> <code>SymbolTable</code>
   * <code>vector</code> structure related to the variable <code>name</code>.
   *
   * @return int The <t>int</t> vector value associated w/ <tt>name</tt>
   * @see Expression::evaluate()
   */
  int evaluate() override;

 private:
  string name;
};
#endif  // VARIABLE_H