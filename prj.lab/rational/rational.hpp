#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <numeric>
#include <sstream>

class Rational {
 public:
  Rational();
  Rational(const Rational&) = default;
  Rational(int64_t num, int64_t den);
  Rational(int64_t num) : num_{num}, den_{1} {};
  ~Rational() = default;

  Rational operator-() const { return Rational(-num_, den_); }

  Rational& operator=(const Rational& rhs);
  Rational& operator=(const int64_t rhs);

  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int64_t rhs);

  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int64_t rhs);

  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int64_t rhs);

  Rational& operator/=(const Rational& rhs);
  Rational& operator/=(const int64_t rhs);

  int64_t num() const;
  int64_t den() const;
  std::istream& readFrom(std::istream& istr);
  std::ostream& writeTo(std::ostream& ostr) const;

 private:
  int64_t num_{0};
  int64_t den_{1};
  void ChangeRational();
  static const char slash{'/'};
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs);

std::istream& operator>>(std::istream& istrm, Rational& rhs);

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, int64_t rhs);
Rational operator+(int64_t lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, int64_t rhs);
Rational operator-(int64_t lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, int64_t rhs);
Rational operator*(int64_t lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, int64_t rhs);
Rational operator/(int64_t lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);
bool operator==(const int64_t lhs, const Rational& rhs);
bool operator==(const Rational& lhs, const int64_t rhs);

bool operator!=(const Rational& lhs, const Rational& rhs);
bool operator!=(const Rational& lhs, const int64_t rhs);
bool operator!=(const int64_t lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const int64_t rhs);
bool operator<(const int64_t lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const int64_t rhs);
bool operator>(const int64_t lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const int64_t rhs);
bool operator<=(const int64_t lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const int64_t rhs);
bool operator>=(const int64_t lhs, const Rational& rhs);

bool testParse(const std::string& str);

#endif