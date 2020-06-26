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
 * @brief Describes the Fraction class, made for fraction calculations
 *
 */
#ifndef FRACTION_H_
#define FRACTION_H_

#include <iostream>

/**
 * @brief The Fraction class represents a fraction and provides fraction calculation operators
 */
class Fraction {
private:
  /**
   * @brief The numerator of the fraction
   */
  int numerator;

  /**
   * @brief The denominator of the fraction
   */
  int denominator;

public:

  /**
   * @brief Creates a new Fraction @p numerator/denominator
   * @param numerator   The numerator of the fraction
   * @param denominator The denominator of the fraction
   */
  Fraction(int numerator, int denominator);

  virtual ~Fraction();

  /**
   * @brief Copy constructor
   * @param other The Fraction to copy
   */
  Fraction(const Fraction& other);
  
  /**
   * @brief Assignment operator. Sets the values on this fraction to the ones from @p other
   * @param other The Fraction to take the values from
   * @return <tt>*this</tt>
   */
  Fraction& operator=(const Fraction& other);

  /**
   * @brief Multiplication operator
   * @param other The Fraction to multiply this Fraction with
   * @return The resulting Fraction
   */
  Fraction operator*(const Fraction& other) const;
  /**
   * @brief Division operator. Is the same as multiplying this with the inverse of @p other
   * @param other The Fraction to divide from this Fraction
   * @return The resulting Fraction
   */
  Fraction operator/(const Fraction& other) const;

  /**
   * @brief @c int multiplication operator
   * @param other The @c int to multiply this Fraction with
   * @return The resulting Fraction
   */
  Fraction operator*(const int& other) const;
  /**
   * @brief @c int division operator. Is the same as multiplying this with <tt>Fraction(1, other)</tt>
   * @param other The @c int to divide from this Fraction
   * @return The resulting Fraction
   */
  Fraction operator/(const int& other) const;

  /**
   * @brief Addition operator. Calculates the lowest common divisor for getting them to the same denominator before adding them.
   * @p other is not a reference, so it gets copied and can be modified inside the function
   * @param other The Fraction to add to this
   * @return The resulting Fraction
   */
  Fraction operator+(Fraction other) const;
  /**
   * @brief Subtraction operator. Calculates the lowest common divisor for getting them to the same denominator before subtracting them.
   * @p other is not a reference, so it gets copied and can be modified inside the function
   * @param other The Fraction to subtract from this
   * @return The resulting Fraction
   */
  Fraction operator-(Fraction other) const;

  /**
   * @brief @c int addition operator. Is the same as adding <tt>Fraction(other, 1)</tt> to this
   * @param other The @c int to add to this
   * @return The resulting Fraction
   */
  Fraction operator+(const int& other) const;
  /**
   * @brief @c int subtraction operator. Is the same as subtracting <tt>Fraction(other, 1)</tt> from this
   * @param other The @c int to subtract from this
   * @return The resulting Fraction
   */
  Fraction operator-(const int& other) const;

  /**
   * @brief Adds @p other to @c this and writes the result into @c this
   * @param other The Fraction to add to @c this
   * @return @c *this
   * @see operator+(Fraction other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator+=(const Fraction& other);
  /**
   * @brief Subtracts @p other from @c this and writes the result into @c this
   * @param other The Fraction to subtract from @c this
   * @return @c *this
   * @see operator-(Fraction other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator-=(const Fraction& other);

  /**
   * @brief Adds @p other to @c this and writes the result into @c this
   * @param other The @c int to add to @c this
   * @return @c *this
   * @see operator+(const int& other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator+=(const int& other);
  /**
   * @brief Subtracts @p other from @c this and writes the result into @c this
   * @param other The @c int to subtract from @c this
   * @return @c *this
   * @see operator-(const int& other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator-=(const int& other);

  /**
   * @brief Multiplies @p other with @c this and writes the result into @c this
   * @param other The Fraction to multiply with @c this
   * @return @c *this
   * @see operator*(const Fraction& other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator*=(const Fraction& other);
  /**
   * @brief Divides @p other from @c this and writes the result into @c this
   * @param other The Fraction to divide from @c this
   * @return @c *this
   * @see operator/(const Fraction& other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator/=(const Fraction& other);

  /**
   * @brief Multiplies @p other with @c this and writes the result into @c this
   * @param other The @c int to multiply with @c this
   * @return @c *this
   * @see operator*(const int& other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator*=(const int& other);
  /**
   * @brief Divides @p other from @c this and writes the result into @c this
   * @param other The @c int to divide from @c this
   * @return @c *this
   * @see operator/(const int& other) const
   * @see operator=(const Fraction& other)
   */
  Fraction& operator/=(const int& other);

  /**
   * @brief Prefix ++ operator (Adds 1 to @c this and returns @c *this afterwards)
   * @return @c *this
   */
  Fraction& operator++();
  /**
   * @brief Prefix -- operator (Subtracts 1 from @c this and returns @c *this afterwards)
   * @return @c *this
   */
  Fraction& operator--();

  /**
   * @brief Postfix ++ operator (copies @c this, adds 1 to @c this and returns the copy)
   * @return A copy of @c this from before it gets incremented
   */
  Fraction operator++(int);
  /**
   * @brief Postfix -- operator (copies @c this, subtracts 1 from @c this and returns the copy)
   * @return A copy of @c this from before it gets decremented
   */
  Fraction operator--(int);

  /**
   * @brief Casts the Fraction to an @c int by calculating <tt>numerator/denominator</tt>
   */
  operator int() const;
  /**
   * @brief Casts the Fraction to a @c double by calculating <tt>(double)numerator/(double)denominator</tt>
   */
  operator double() const;

  /**
   * @brief Reduces the Fraction and returns it without modifying the object itself. Example: <tt>Fraction(2, 8).reduce()</tt> returns <tt>Fraction(1, 4)</tt>
   * @return The reduced Fraction
   */
  Fraction reduce() const;

  /**
   * @brief The denominator of the Fraction
   * @return The denominator
   */
  int getDenominator() const;

  /**
   * @brief The numerator of the Fraction
   * @return The numerator
   */
  int getNumerator() const;
};

/**
 * @brief Calculates the greatest common divisor of @p a and @p b
 * @param a The first value
 * @param b The second value
 * @return The calculated greatest common divisor of @p a and @b
 */
int calcGreatestCommonDivisor(int a, int b);

/**
 * @brief Calculates the lowest common multiple of @p a and @p b
 * @param a The first value
 * @param b The second value
 * @return The calculated lowest common multiple of @p a and @p b
 */
int calcLowestCommonMultiple(int a, int b);

/**
 * @brief Writes <tt>f.getNumerator() + "/" + f.getDenominator()</tt> to @p os
 * @param os  The std::ostream to write to
 * @param f   The Fraction to write
 * @return @p os
 */
std::ostream& operator<<(std::ostream& os, Fraction f);

#endif /* FRACTION_H_ */
