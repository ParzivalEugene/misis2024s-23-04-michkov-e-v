#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational {
 public:
  [[nodiscard]] Rational() = default;
  [[nodiscard]] Rational(const Rational&) = default;
  [[nodiscard]] explicit Rational(const int64_t num) noexcept : num_(num) {}
  [[nodiscard]] Rational(const int64_t num, const int64_t den);
  ~Rational() = default;
  [[nodiscard]] Rational& operator=(const Rational&) = default;

  [[nodiscard]] int64_t num() const noexcept { return num_; }
  [[nodiscard]] int64_t den() const noexcept { return den_; }

  [[nodiscard]] bool operator==(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator<=(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>(const Rational& rhs) const noexcept;
  [[nodiscard]] bool operator>=(const Rational& rhs) const noexcept;

  [[nodiscard]] Rational operator-() const noexcept { return {-num_, den_}; }

  Rational& operator+=(const Rational& rhs) noexcept;
  Rational& operator-=(const Rational& rhs) noexcept;
  Rational& operator*=(const Rational& rhs) noexcept;
  Rational& operator/=(const Rational& rhs);

  Rational& operator+=(const int64_t rhs) noexcept;
  Rational& operator-=(const int64_t rhs) noexcept;
  Rational& operator*=(const int64_t rhs) noexcept;
  Rational& operator/=(const int64_t rhs);

  std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
  std::istream& ReadFrom(std::istream& istrm) noexcept;

 private:
  int64_t num_ = 0;
  int64_t den_ = 1;

  static const char slash{'/'};

  int64_t GCD(int64_t a, int64_t b) const noexcept;
  void Normalize() noexcept;
};

[[nodiscard]] Rational operator+(const Rational& lhs,
                                 const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs,
                                 const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs,
                                 const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const Rational& rhs);

[[nodiscard]] Rational operator+(const Rational& lhs,
                                 const int64_t rhs) noexcept;
[[nodiscard]] Rational operator-(const Rational& lhs,
                                 const int64_t rhs) noexcept;
[[nodiscard]] Rational operator*(const Rational& lhs,
                                 const int64_t rhs) noexcept;
[[nodiscard]] Rational operator/(const Rational& lhs, const int64_t rhs);

[[nodiscard]] Rational operator+(const int64_t lhs,
                                 const Rational& rhs) noexcept;
[[nodiscard]] Rational operator-(const int64_t lhs,
                                 const Rational& rhs) noexcept;
[[nodiscard]] Rational operator*(const int64_t lhs,
                                 const Rational& rhs) noexcept;
[[nodiscard]] Rational operator/(const int64_t lhs, const Rational& rhs);

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) noexcept;
std::istream& operator>>(std::istream& istrm, Rational& rhs) noexcept;

#endif