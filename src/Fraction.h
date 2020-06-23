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
 FILE:       Fraction.h
 CONTENTS:
 TODO Add contents
 */

/*[CL]**************************************************************************

 23.06.2020  TW  Erste Implementierung

 ---
 TW:  Tobias Waßmundt
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
  Fraction(const Fraction &other);
  Fraction(Fraction &&other);
  Fraction& operator=(const Fraction &other);

  Fraction operator*(const Fraction& other) const;
  Fraction operator/(const Fraction& other) const;

  Fraction operator*(const int& other) const;
  Fraction operator/(const int& other) const;

  Fraction operator+(Fraction other) const;
  Fraction operator-(Fraction other) const;

  operator int() const;
  operator double() const;

  Fraction shorten() const;

  int getDenominator() const;
  int getNumerator() const;
};

int calcGreatestCommonDivisor(int a, int b);
int calcLowestCommonMultiple(int a, int b);

std::ostream& operator<<(std::ostream& os, Fraction f);

#endif /* FRACTION_H_ */
