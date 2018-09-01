/**
 * Variable.cpp
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#include <sstream>
#include <vector>

using namespace std;

#include "expression.h"
#include "operand.h"
#include "variable.h"
#include "symboltable.h"

extern SymbolTable symbolTable;

/**
 * This method is identical to that in the Module 3 codebase, apart from the
 * fact that it now returns an <code>int</code> rather than <code>double</code>,
 * in accordance with the Project 2 rubric. It serves as a lookup method used
 * to call the <code>SymbolTable</code> instance's own
 * <code>SymbolTable::lookUp()</code> method and find the <code>int</code> value
 * associated with the class private <code>name</code> <code>string</code>.
 *
 * @return <code>int</code> value associated w/ class's <code>name</code> field
 * @see Expression::evaluate()
 */
int Variable::evaluate() {
  return symbolTable.lookUp(name);
}