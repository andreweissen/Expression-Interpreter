/**
 * Operand.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef OPERAND_H
#define OPERAND_H

#include "expression.h"

/**
 * This class is used to define leaf nodes of the arithmetic expression tree in
 * the inheritance hierarchy that contain variables and literal values. It is a
 * subclass extension of the parent class <code>Expression</code> and has child
 * subclasses <code>Variable</code> and <code>Literal</code>.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @see Expression
 */
class Operand : public Expression {
 public:

  /**
   * This method is a modified static method initially included in the Module 3.
   * It has been modified somewhat to allow it to accept a reference parameter
   * representing user file input string stream value.
   *
   * @param iss <code>istringstream</code> reference
   * @return Expression* Literal, Variable, or SubExpression subclass instance
   */
  static Expression* parse(istringstream& iss);
};
#endif  // OPERAND_H