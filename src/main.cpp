
#include "Fraction.h"

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char **argv) {
  Fraction f1(3, 9);
  Fraction f2(3, 10);

  Fraction f3 = f1 + f2;
  cout << f1 << "+" << f2 << "=" << f3 << "=" << f3.shorten() << endl;

  f3 = f3.shorten() * 3;
  cout << "(int)" << f3 << "=" << (int)f3 << endl;
  cout << "(double)" << f3 << "=" << (double)f3 << endl;

  f3 = Fraction(16, 8);

  cout << "(int)" << f3 << "=" << (int)f3 << endl;
  cout << "(double)" << f3 << "=" << (double)f3 << endl;

  cout << "(" << f1 << ")/(" << f2 << ")=" << (f1 / f2).shorten() << endl;
}
