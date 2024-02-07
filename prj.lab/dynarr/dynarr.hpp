#pragma once
#ifndef DYNARR_H
#define DYNARR_H

#include <cstddef>

class DynArr {
 public:
  [[nodiscard]] DynArr() = default;
  [[nodiscard]] DynArr(const DynArr&) = default;
  [[nodiscard]] DynArr(const ptrdiff_t size);
  ~DynArr() = default;
  [[nodiscard]] DynArr& operator=(const DynArr&) = default;

  ptrdiff_t Size() const noexcept;
  void Resize(const ptrdiff_t size);
  float& operator[](const ptrdiff_t idx);
  const float& operator[](const ptrdiff_t idx) const;

 private:
  ptrdiff_t size_ = 0;
  ptrdiff_t capacity_ = 0;
  float* data_ = 0;
};

#endif