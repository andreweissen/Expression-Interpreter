/**
 * Parse.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef PARSE_H
#define PARSE_H

/**
 * This method is a helper utility method used to assist in the parsing of
 * element types encountered in each expression. It is used in the classes
 * <code>module3.cpp</code> and <code>operand.cpp</code>.
 *
 * @param iss Line-based <code>istringstream</code> reference
 * @return string <code>name</code>
 */
string parseName(istringstream& iss);
#endif  // PARSE_H