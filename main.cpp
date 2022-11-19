#include <iostream>

using namespace std;

class Box {
public:
  string name;
  int count;
  Box(string name) : name{name}, count{0} {}
  Box(string name, int count) : name{name}, count{count + 3} {}
  Box(const Box &b) : name{b.name + "-2"}, count{b.count + 5} {}
  ~Box() { cout << name << ": " << count << endl; }
  Box trick(Box b1, Box &b2, int add) {
    Box bfinal = b1;
    bfinal.count += add;
    b2.count += add;
    return bfinal;
  }
};

void test1() {
  Box ba("ba");
  Box bb("bb", 10);
  Box bc(ba);
  Box bd = ba.trick(bb, bc, 7);
}

void test2() {
  Box ba("ba");
  Box bb("bb", 10);
  ba = bb;
  Box bc = bb;
}

int main() {
  // test1();
  test2();
  return 0;
}