#pragma once
#ifndef DYNARR_HPP
#define DYNARR_HPP

#include <cstdint>
#include <iostream>
#include <sstream>

class DynArr {
 public:
  DynArr() = default;
  DynArr(const DynArr& rhs);
  DynArr(const ptrdiff_t size);
  DynArr(std::initializer_list<float> il);
  DynArr(DynArr&&) noexcept;
  ~DynArr();

  DynArr& operator=(DynArr&&) noexcept;
  DynArr& operator=(const DynArr& rhs);

  ptrdiff_t Size() const { return size_; }
  ptrdiff_t Capacity() const { return capacity_; }
  void Resize(const ptrdiff_t size);
  float& operator[](const ptrdiff_t idx);
  const float& operator[](const ptrdiff_t idx) const;
  std::ostream& Print(std::ostream& ostrm) const;

 private:
  float* data_ = nullptr;
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
};

std::ostream& operator<<(std::ostream& ostrm, const DynArr& rhs);

#endif