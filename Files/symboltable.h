/**
 * SymbolTable.h
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 * @version 1.0
 * @see <a href="http://ccdoc.sourceforge.net/">Ccdoc</a>
 */
#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

/**
 * This class is used to construct a symbol table implemented via an unsorted
 * list, a <code>vector</code> dynamically-resizing array structure. Entries,
 * <code>struct</code> elements named <code>Symbol</code>s, have a variable and
 * an associated value and are stored for use therein.
 *
 * @author Andrew Eissen
 * @author UMUC Dept.CS
 */
class SymbolTable {
 public:

  // Default constructor
  SymbolTable() {}

  /**
   * This function is simply used to add an entry to the <code>vector</code>
   * dynamically-resizing array structure, inserting a new <code>Symbol</code>
   * <code>struct</code> element into the <code>elements</code> structure.
   *
   * @param variable <code>string</code>
   * @param value <code>int</code>
   * @return void
   */
  void insert(string variable, int value);

  /**
   * The second default method of the class, this function simply returns the
   * associated <code>value</code> of the parameter-supplied
   * <code>variable</code> <code>string</code>. It makes use of a standard
   * <code>for</code> loop traversal and comparison operation to find the right
   * element.
   *
   * @param variable <code>string</code>
   * @return int The associated <code>value</code> value
   */
  int lookUp(string variable) const;

  /**
   * This method is called within the body of <code>module3.cpp</code>'s
   * <code>main</code> method and simply calls the <code>vector::clear()</code>
   * function to remove prior elements stored in the <code>elements</code>
   * <code>vector</code>.
   *
   * @return void
   * @see <a href="https://stackoverflow.com/questions/13640217">SO Thread</a>
   */
  void reset();

 private:

  /**
   * This inner class is used to represent the individual elements, instances of
   * which are constructed within the body of <code>SymbolTable::insert()</code>
   * & indirectly by <code>module3.cpp</code>'s <code>parseAssignments()</code>.
   *
   * @author Andrew Eissen
   * @author UMUC Dept.CS
   */
  struct Symbol {

    /**
     * Parameterized constructor
     * @param variable <code>string</code>
     * @param value <code>int</code>
     */
    Symbol(string variable, int value) {
      this->variable = variable;
      this->value = value;
    }

    string variable;
    int value;
  };

  // Dynamic array structure
  vector<Symbol> elements;
};
#endif  // SYMBOLTABLE_H