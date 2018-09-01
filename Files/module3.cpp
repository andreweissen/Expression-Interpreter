/**
 * Module3.cpp
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(istringstream& iss);

/**
 * This method, <code>main</code>, handles text files and all matters related to
 * this process. The user is prompted to enter a text file name in the console
 * from which the contents will be parsed. Assuming this file exists, the
 * contents are split into a series of individual lines (each of which is
 * assumed to be a properly formatted expression in its own right) which are
 * then rendered as string streams (similar to <code>cin</code>) to keep much of
 * the Module 3 base code intact. The appropriate expression tree is constructed
 * and the appropriate value displayed below the expression in the console.
 * <br />
 * <br />
 * The author elected to make use of an <code>istringstream</code> in an effort
 * to preserve as much of the base Module 3 code as possible, thereby
 * simplifying his task considerably. Before the author learned of streams, he
 * attempted an approach similar to that evidenced in Project 1, basically
 * cutting the file into individual lines, looking at the <code>char</code>s in
 * those lines one by one in an effort to determine type, then assembling the
 * tree as needed. However, this required the use of a counter <code>int</code>
 * and a lot of messy parameter passing (or global variable use, depending on
 * the implementation), so the author went looking for better approaches. The
 * <code>istringstream</code> was used as a StackOverflow thread suggested that
 * these input streams are more lightweight than the more general
 * <code>stringstream</code>.
 *
 * @return 0 <code>int</code>
 * @see <a href="https://stackoverflow.com/questions/9670396">SO Thread #1</a>
 * @see <a href="https://stackoverflow.com/questions/7868936">SO Thread #2</a>
 * @see <a href="https://stackoverflow.com/questions/3946558">SO THread #3</a>
 */
int main() {

  // Declarations
  Expression* expression;
  char paren, comma;
  string fileName;
  ifstream infile;
  int counter;

  // Allow user to specify file name
  cout << "Enter file name: ";
  cin >> fileName;

  // Attempt to open, check if legit file, return if not
  infile.open(fileName);
  if (!infile) {
    cout << "Error: Text file not found or improperly formatted.";
    return EXIT_FAILURE;
  }

  counter = 1;
  for (string line; getline(infile, line);) {

    // Clear the vector if necessary
    symbolTable.reset();

    // Make use of istringstream for each individual line
    istringstream iss(line);

    // Slightly modified from Module 3
    iss >> paren;
    cout << "Expression #" << counter++ << ": " << line << endl;
    expression = SubExpression::parse(iss);
    iss >> comma;
    parseAssignments(iss);
    cout << "Value = " << expression->evaluate() << "\n" << endl;
  }

  // Remember to close the file reader thingie once completed
  infile.close();
  return 0;
}

/**
 * Basically the same as the Module 3 default implementation, this method's main
 * modification comes in the form of a type switch from <code>double</code> to
 * <code>int</code>, as denoted in the Project 2 rubric. Also, a new parameter
 * is passed for use, namely the string stream <code>iss</code>.
 *
 * @param iss <code>istringstream</code> reference
 * @return void
 */
void parseAssignments(istringstream& iss) {

  // Declarations
  char assignop, delimiter;
  string variable;
  int value;

  do {
    variable = parseName(iss);
    iss >> ws >> assignop >> value >> delimiter;
    symbolTable.insert(variable, value);
  } while (delimiter == ',');
}