/**
 * @file
 *
 * @copyright
 * MIT License
 * @copyright
 * Copyright (c) 2020 Doubi88 <tobis_mail@yahoo.de>
 * @copyright
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * @copyright
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * @copyright
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @author Doubi88 <tobis_mail@yahoo.de>
 * @brief Implementation of the Fraction class
 *
 */

#include "Fraction.h"

Fraction::Fraction(int numerator, int denominator): numerator(numerator), denominator(denominator){}

Fraction::~Fraction(){}

Fraction::Fraction(const Fraction &other): numerator(other.numerator), denominator(other.denominator){}

Fraction& Fraction::operator=(const Fraction &other){
  numerator = other.numerator;
  denominator = other.denominator;
  return *this;
}

Fraction Fraction::operator*(const Fraction& other) const {
  Fraction result(this->numerator * other.numerator, this->denominator * other.denominator);
  return result;
}

Fraction Fraction::operator/(const Fraction& other) const {
  Fraction result(this->numerator * other.denominator, this->denominator * other.numerator);
  return result;
}

Fraction Fraction::operator*(const int& other) const {
  Fraction result(this->numerator * other, this->denominator);
  return result;
}
Fraction Fraction::operator/(const int& other) const {
  Fraction result(this->numerator, this->denominator * other);
  return result;
}

Fraction Fraction::operator+(Fraction other) const {
  Fraction result(*this);
  int lowestCommonDivisor = calcLowestCommonMultiple(this->denominator, other.denominator);
  result.denominator = lowestCommonDivisor;

  result.numerator *= (lowestCommonDivisor / this->denominator);
  other.numerator *= (lowestCommonDivisor / other.denominator);

  result.numerator = result.numerator + other.numerator;
  return result;
}

Fraction Fraction::operator-(Fraction other) const {
  Fraction result(*this);
  int lowestCommonDivisor = calcLowestCommonMultiple(this->denominator, other.denominator);
  result.denominator = lowestCommonDivisor;

  result.numerator *= (lowestCommonDivisor / this->denominator);
  other.numerator *= (lowestCommonDivisor / other.denominator);

  result.numerator = result.numerator - other.numerator;
  return result;
}

Fraction& Fraction::operator+=(const Fraction& other) {
  *this = *this + other;
  return *this;
}
Fraction& Fraction::operator-=(const Fraction& other) {
  *this = *this - other;
  return *this;
}

Fraction Fraction::operator+(const int &other) const {
  Fraction otherF(other, 1);
  Fraction result = *this + otherF;
  return result;
}
Fraction Fraction::operator-(const int& other) const {
  Fraction otherF(other, 1);
  Fraction result = *this - otherF;
  return result;
}

Fraction& Fraction::operator+=(const int& other) {
  Fraction otherF(other, 1);
  *this += otherF;
  return *this;
}
Fraction& Fraction::operator-=(const int& other) {
  Fraction otherF(other, 1);
  *this -= otherF;
  return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
  *this = *this * other;
  return *this;
}
Fraction& Fraction::operator/=(const Fraction& other) {
  *this = *this / other;
  return *this;
}

Fraction& Fraction::operator*=(const int& other) {
  *this = *this * other;
  return *this;
}
Fraction& Fraction::operator/=(const int& other) {
  *this = *this / other;
  return *this;
}

Fraction& Fraction::operator++() {
  *this += 1;
  return *this;
}

Fraction& Fraction::operator--() {
  *this -= 1;
  return *this;
}

Fraction Fraction::operator++(int) {
  Fraction result(*this);
  ++(*this);
  return result;
}

Fraction Fraction::operator--(int) {
  Fraction result(*this);
  --(*this);
  return result;
}

Fraction::operator int() const {
  return numerator / denominator;
}

Fraction::operator double() const {
  return (double)numerator / (double)denominator;
}

Fraction Fraction::reduce() const {
  int lcd = calcGreatestCommonDivisor(numerator, denominator);
  Fraction result(numerator / lcd, denominator / lcd);
  return result;
}

int Fraction::getNumerator() const {
  return numerator;
}

int Fraction::getDenominator() const {
  return denominator;
}

int calcGreatestCommonDivisor(int a, int b) {
  int result = b;
  if (a != 0) {
    result = calcGreatestCommonDivisor(b % a, a);
  }
  return result;
}

int calcLowestCommonMultiple(int a, int b){
  return (a * b) / calcGreatestCommonDivisor(a, b);
}

std::ostream& operator<<(std::ostream &os, Fraction f) {
  os << f.getNumerator() << '/' << f.getDenominator();
  return os;
}
