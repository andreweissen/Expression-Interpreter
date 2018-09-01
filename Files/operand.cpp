/**
 * Operand.cpp
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#include <cctype>
#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

/**
 * Very little has been altered in this method from its initial implementation
 * in the body of the Module 3 codebase. The major change comes in the form of
 * the new parameter, <code>iss</code>, being passed and used to replace the
 * previous <code>cin</code> standard console input implementation. Further
 * edits were made to adjust and standardize format in accordance with Google's
 * styleguide.
 *
 * @param iss <code>istringstream</code> reference
 * @return <code>Expression</code> type
 */
Expression* Operand::parse(istringstream& iss) {

  // Declarations
  char paren;
  int value;

  iss >> ws;
  if (isdigit(iss.peek())) {
    iss >> value;
    Expression* literal = new Literal(value);
    return literal;
  }

  if (iss.peek() == '(') {
    iss >> paren;
    return SubExpression::parse(iss);
  } else {
    return new Variable(parseName(iss));
  }

  return 0;
}