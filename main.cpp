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

void test3() {
  Box ba("ba");     // call constructor
  Box bb = ba;      // call copy constructor
  Box bc = get10(); // copy elision, copy constructor not called
}

int main() {
  cout << "Test-1" << endl;
  test1();
  // cout << "Test-2" << endl;
  // test2();
  // cout << "test-3" << endl;
  // test3();
  return 0;
}