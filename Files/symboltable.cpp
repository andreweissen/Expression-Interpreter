/**
 * SymbolTable.cpp
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#include <string>
#include <vector>

using namespace std;

#include "symboltable.h"

/**
 * This method is identical to that initially implemented in the Module 3
 * codebase defaults. As is the case with the original, it is a helper method
 * used to add new <code>Symbol</code> <code>struct</code>s to the table. It is
 * called within the body of <code>module3.cpp</code>'s
 * <code>parseAssignments</code> method. The only change comes in the form of
 * the parameter type switch from <code>double</code> to <code>int</code>.
 *
 * @param variable <code>string</code> variable name
 * @param value <code>int</code> associated value
 * @return void
 */
void SymbolTable::insert(string variable, int value) {
  const Symbol& symbol = Symbol(variable, value);
  elements.push_back(symbol);
}

/**
 * Another of the default methods from the original Module 3 codebase, this
 * method has also been left mostly alone, apart from some Google styleguide-
 * suggested format fixes, namely the addition of brackets to <code>if</code>
 * statements. It employs a basic <code>for</code> loop driven comparison
 * algorithm to find the proper <code>value</code> associated with the provided
 * <code>string</code> variable name.
 *
 * @param variable <code>string</code> variable name
 * @return value <code>int</code> associated value
 */
int SymbolTable::lookUp(string variable) const {
  for (int i = 0; i < elements.size(); i++) {
    if (elements[i].variable == variable) {
      return elements[i].value;
    }
  }
  return -1;
}

/**
 * This utility method is simply used to clear the table of old entries to
 * ensure that new lines of expression in the text file are handled properly. It
 * is called with the body of the <code>main</code> method's <code>for</code>
 * loop.
 *
 * @return void
 * @see <a href="https://stackoverflow.com/questions/13640217">SO Thread</a>
 */
void SymbolTable::reset() {
  this->elements.clear();
}