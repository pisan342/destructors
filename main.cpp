/**
 * Constructor can be called explicitly
 * Constructor can be called implicitly if it is not defined as explicit
 *
 * Copy-constructor can be called explicitly
 * Copy-constructor called when passed by value
 * Copy constructor called for = statement when a new variable is initialized
 *
 * Copy elision: if a temporary value is going to be assignned to a new
 *variable, instead of copy-move, compiler must construct the value in place for
 *the new variable. Copy constructor is *not* called
 *
 * Items are allocated on the stack and destructor is called on them
 * in the opposite order they were created.
 *
 **/

#include <iostream>

using namespace std;

class Box {
public:
  string name;
  int count;
  // constructor with one argument
  Box(string name) : name{name}, count{0} {}
  // constructor with 2 arguments
  Box(string name, int count) : name{name}, count{count + 3} {}
  // copy constructor
  Box(const Box &b) : name{b.name + "-2"}, count{b.count + 5} {
    cout << "> Copy Constructor " << b.name << "(" << b.count << ") ==> "
         << name << "(" << count << ")" << endl;
  }
  // Box &operator=(const Box &b) {
  //   name = b.name;
  //   count = b.count;
  //   cout << "> operator= " << b.name << "(" << b.count << ") ==> " << name
  //        << "(" << count << ")" << endl;
  //   return *this;
  // }
  // Box(Box &&b) {
  //   name = b.name;
  //   count = b.count;
  //   cout << "> Move operator " << b.name << "(" << b.count << ") ==> " <<
  //   name
  //        << "(" << count << ")" << endl;
  // }
  // destructor
  ~Box() { cout << name << ": " << count << endl; }
  // trick takes parameters by value (i.e the objects are copied)
  // and returns by value (i.e. the object is copied)
  Box trick(Box b1, Box &b2, int add) {
    cout << "Before bfinal b1 count is " << b1.count << endl;
    Box bfinal = b1;
    bfinal.count += add;
    b2.count += add;
    cout << "end trick bfinal count is " << bfinal.count << endl;
    return bfinal;
  }
};

void test1() {
  Box ba("ba");
  Box bb("bb", 10);
  Box bc(ba);
  Box bd = ba.trick(bb, bc, 7);
  bd.name = "bd";
  cout << "end test1 bd count is " << bd.count << endl;
}

void test2() {
  Box ba("ba");
  Box bb("bb", 10);
  ba = bb;
  Box bc = bb;
}

Box get10() {
  Box b("b");
  b.count = 10;
  return b;
}

// copy elision - instead of a copy-move operation for the temporary value
// the value is constructed in-place
void test3() {
  Box ba("ba");     // call constructor
  Box bb = ba;      // call copy constructor
  Box bc = get10(); // copy elision, copy constructor not called
}

void displayBoxString(Box b) { cout << "displayBoxString: " << b.name << endl; }

// if the Box constructor with single parameter does not have explicit
// the below function will compile and run
// The compiler use the Box constructor to implicitly convert a string
// into a Box object and the calls displayBoxString
void test4() {
  Box b("b");
  displayBoxString(b);
  string s = "test";
  displayBoxString(s);
}

int main() {
  cout << "Test-1" << endl;
  test1();
  // cout << "Test-2" << endl;
  // test2();
  // cout << "test-3" << endl;
  // test3();
  return 0;
  // cout << "test-4" << endl;
  // test4();
}