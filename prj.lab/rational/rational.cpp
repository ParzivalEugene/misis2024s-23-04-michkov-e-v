#include "rational.hpp"

#include <numeric>
#include <stdexcept>

Rational::Rational(const int64_t num, const int64_t den) {
  if (den == 0) {
    throw std::invalid_argument("Denominator cannot be zero");
  }
  num_ = num;
  den_ = den;
  Normalize();
}

bool Rational::operator==(const Rational& rhs) const noexcept {
  return num_ == rhs.num_ && den_ == rhs.den_;
}

bool Rational::operator!=(const Rational& rhs) const noexcept {
  return !(*this == rhs);
}

bool Rational::operator<(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ < rhs.num_ * den_;
}

bool Rational::operator<=(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ <= rhs.num_ * den_;
}

bool Rational::operator>(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ > rhs.num_ * den_;
}

bool Rational::operator>=(const Rational& rhs) const noexcept {
  return num_ * rhs.den_ >= rhs.num_ * den_;
}

Rational& Rational::operator+=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ + rhs.num_ * den_;
  den_ *= rhs.den_;
  Normalize();
  return *this;
}

Rational& Rational::operator-=(const Rational& rhs) noexcept {
  num_ = num_ * rhs.den_ - rhs.num_ * den_;
  den_ *= rhs.den_;
  Normalize();
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) noexcept {
  num_ *= rhs.num_;
  den_ *= rhs.den_;
  Normalize();
  return *this;
}

Rational& Rational::operator/=(const Rational& rhs) {
  if (rhs.num_ == 0) {
    throw std::invalid_argument("Cannot divide by zero");
  }
  num_ *= rhs.den_;
  den_ *= rhs.num_;
  Normalize();
  return *this;
}

Rational& Rational::operator+=(const int64_t rhs) noexcept {
  num_ += rhs * den_;
  Normalize();
  return *this;
}

Rational& Rational::operator-=(const int64_t rhs) noexcept {
  num_ -= rhs * den_;
  Normalize();
  return *this;
}

Rational& Rational::operator*=(const int64_t rhs) noexcept {
  num_ *= rhs;
  Normalize();
  return *this;
}

Rational& Rational::operator/=(const int64_t rhs) {
  if (rhs == 0) {
    throw std::invalid_argument("Cannot divide by zero");
  }
  den_ *= rhs;
  Normalize();
  return *this;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const noexcept {
  ostrm << num_ << slash << den_;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) noexcept {
  int64_t num{0};
  int64_t den{0};
  char slash{' '};
  istrm >> num >> slash >> den;
  if (istrm.good()) {
    if (slash == Rational::slash) {
      num_ = num;
      den_ = den;
      Normalize();
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

int64_t Rational::GCD(int64_t a, int64_t b) const noexcept {
  while (b != 0) {
    int64_t t = b;
    b = a % b;
    a = t;
  }
  return a;
}

void Rational::Normalize() noexcept {
  if (den_ < 0) {
    den_ = -den_;
    num_ = -num_;
  }
  int64_t gcd = GCD(abs(num_), den_);
  num_ /= gcd;
  den_ /= gcd;
}

Rational operator+(const Rational& lhs, const Rational& rhs) noexcept {
  Rational result(lhs);
  result += rhs;
  return result;
}

Rational operator-(const Rational& lhs, const Rational& rhs) noexcept {
  Rational result(lhs);
  result -= rhs;
  return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs) noexcept {
  Rational result(lhs);
  result *= rhs;
  return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational result(lhs);
  result /= rhs;
  return result;
}

Rational operator+(const Rational& lhs, const int64_t rhs) noexcept {
  Rational result(lhs);
  result += rhs;
  return result;
}

Rational operator-(const Rational& lhs, const int64_t rhs) noexcept {
  Rational result(lhs);
  result -= rhs;
  return result;
}

Rational operator/(const Rational& lhs, const int64_t rhs) {
  Rational result(lhs);
  result /= rhs;
  return result;
}

Rational operator+(const int64_t lhs, const Rational& rhs) noexcept {
  Rational result(rhs);
  result += lhs;
  return result;
}

Rational operator-(const int64_t lhs, const Rational& rhs) noexcept {
  return Rational(lhs) - rhs;
}

Rational operator*(const int64_t lhs, const Rational& rhs) noexcept {
  Rational result(rhs);
  result *= lhs;
  return result;
}

Rational operator/(const int64_t lhs, const Rational& rhs) {
  return Rational(lhs) / rhs;
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept {
  return rhs.WriteTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept {
  return rhs.ReadFrom(istrm);
}
