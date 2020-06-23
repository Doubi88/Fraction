/*[CR]**************************************************************************
 Copyright (C) JOERG ELEKTRONIK GMBH
 All rights reserved. No part of this program may be reproduced,
 transmitted, transcribed, stored in a retrieval system,
 translated or copied without the prior written permission of
 J O E R G  Elektronik GmbH, 87534 Oberstaufen, Bauhofweg 2
 */

/*[FH]**************************************************************************

 PROJECT:    Projekt Test
 MODULE:     Test
 FILE:       Fraction.cpp
 CONTENTS:
 TODO Add contents
 */

/*[CL]**************************************************************************

 23.06.2020  TW  Erste Implementierung

 ---
 TW:  Tobias Waßmundt
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

Fraction::operator int() const {
  return numerator / denominator;
}

Fraction::operator double() const {
  return (double)numerator / (double)denominator;
}

Fraction Fraction::shorten() const {
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
