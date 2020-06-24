/*
 * MIT License
 *
 * Copyright (c) 2020 Doubi88 <tobis_mail@yahoo.de>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 */
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
