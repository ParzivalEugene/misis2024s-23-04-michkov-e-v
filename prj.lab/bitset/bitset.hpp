#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <string>

class BitSet {
 public:
  BitSet() = default;
  BitSet(const BitSet&) noexcept;
  BitSet(BitSet&&) noexcept;
  BitSet(const int32_t);
  BitSet& operator=(const BitSet&) noexcept;
  BitSet& operator=(BitSet&&) noexcept;
  ~BitSet() = default;

  [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
  [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;
  [[nodiscard]] BitSet& operator&=(const BitSet& rhs);
  [[nodiscard]] BitSet& operator|=(const BitSet& rhs);
  [[nodiscard]] BitSet& operator^=(const BitSet& rhs);
  [[nodiscard]] BitSet operator~();

  int32_t Size() const noexcept { return size_; }
  void Resize(const int32_t size);
  [[nodiscard]] bool Get(const int32_t idx) const;
  void Set(const int32_t idx, const bool val);
  void Fill(const bool val) noexcept;

  int32_t operator[](const int32_t);
  std::ostream& WriteTxt(std::ostream&);
  std::ostream& WriteBinary(std::ostream&);
  std::istream& ReadTxt(std::istream&);
  std::istream& ReadBinary(std::istream&);

  // custom methods
  BitSet(const std::string&);
  [[nodiscard]] std::string toString() const;

 private:
  int32_t size_ = 0;
  bool* data_ = nullptr;
};

std::ostream& operator<<(std::ostream&, const BitSet&);
std::istream& operator>>(std::istream&, BitSet&);

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);
[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif  // BITSET_HPP
