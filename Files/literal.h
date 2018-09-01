/**
 * Literal.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef LITERAL_H
#define LITERAL_H

#include "operand.h"

/**
 * This class is used to define leaf nodes of the arithmetic expression tree in
 * the inheritance hierarchy that contain literal values. It is a subclass
 * extension of the parent class <code>Operand</code> along with fellow child
 * class <code>Variable</code>.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @see Operand
 */
class Literal : public Operand {
 public:

  /**
   * Parameterized constructor, extends <code>Operand</code>
   * @param value Literal value for tree node
   */
  Literal(int value) {
    this->value = value;
  }

  /**
   * This method/function functions as a getter, returning the class instance
   * variable <code>value</code> related to the literal tree node value.
   *
   * @return int Class private variable <code>value</code>
   * @see Expression::evaluate()
   */
  int evaluate() override {
    return value;
  }

 private:
  int value;
};
#endif  // LITERAL_H