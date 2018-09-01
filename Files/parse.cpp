/**
 * Parse.cpp
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#include <cctype>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include "parse.h"

/**
 * As is the case with many methods implemented in the project's <tt>.cpp</t>
 * files, little is modified in the body of this method, apart from the passing
 * of the <code>istringstream</code> reference as a parameter and its use in
 * replacing the previous <code>cin</code>-based console implementation.
 *
 * @param iss <code>istringstream</code> reference
 * @return name <code>string</code>
 */
string parseName(istringstream& iss) {

  // Declaration
  char alnum;
  string name;

  // Definition
  name = "";

  iss >> ws;
  while (isalnum(iss.peek())) {
    iss >> alnum;
    name += alnum;
  }

  return name;
}