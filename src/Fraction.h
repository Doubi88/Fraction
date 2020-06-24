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
#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

class Fraction {
private:
  int numerator;
  int denominator;

public:
  Fraction(int numerator, int denominator);
  virtual ~Fraction();
  Fraction(const Fraction& other);
  
  Fraction& operator=(const Fraction& other);

  Fraction operator*(const Fraction& other) const;
  Fraction operator/(const Fraction& other) const;

  Fraction operator*(const int& other) const;
  Fraction operator/(const int& other) const;

  Fraction operator+(Fraction other) const;
  Fraction operator-(Fraction other) const;

  Fraction operator+(const int& other) const;
  Fraction operator-(const int& other) const;

  Fraction& operator+=(const Fraction& other);
  Fraction& operator-=(const Fraction& other);

  Fraction& operator+=(const int& other);
  Fraction& operator-=(const int& other);

  Fraction& operator*=(const Fraction& other);
  Fraction& operator/=(const Fraction& other);

  Fraction& operator*=(const int& other);
  Fraction& operator/=(const int& other);

  Fraction& operator++();
  Fraction& operator--();

  Fraction operator++(int);
  Fraction operator--(int);

  operator int() const;
  operator double() const;

  Fraction reduce() const;

  int getDenominator() const;
  int getNumerator() const;
};

int calcGreatestCommonDivisor(int a, int b);
int calcLowestCommonMultiple(int a, int b);

std::ostream& operator<<(std::ostream& os, Fraction f);

#endif /* FRACTION_H_ */
